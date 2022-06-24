/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:36:31 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 04:02:51 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_eating(t_list *philo)
{
	int	eating;
	int	i;

	i = 0;
	eating = 0;
	while (i++ < philo->info->num_of_philos)
	{
		if (philo->num_of_eating == philo->info->num_of_times)
			eating++;
	}
	if (eating == philo->info->num_of_philos)
		return (1);
	else
		return (0);
}

void	*routine(void *list)
{
	t_list	*philo;

	philo = (t_list *)list;
	while (philo->is_alive)
	{
		pthread_mutex_lock(&philo->fork);
		ft_write_philo(philo, 1);
		pthread_mutex_lock(&philo->next->fork);
		ft_write_philo(philo, 1);
		ft_write_philo(philo, 2);
		ft_sleep(philo->info->time_to_eat);
		philo->died += get_time() - philo->info->start;
		philo->num_of_eating += 1;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_write_philo(philo, 3);
		ft_sleep(philo->info->time_to_sleep);
		ft_write_philo(philo, 4);
		if (check_eating(philo))
			philo->info->eating = 0;
	}
	return (NULL);
}

void	ft_end_process(t_list *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->info->write);
	printf ("%ld philo %d is died\n", \
	get_time() - philo->info->start, philo->num);
	pthread_mutex_unlock(&philo->info->write);
	while (i++ < philo->info->num_of_philos)
	{
		philo->is_alive = 0;
		philo = philo->next;
	}
}

void	check_death(t_list *philo)
{
	while (1)
	{
		while (philo)
		{
			if (philo->died <= get_time() - philo->info->start)
			{
				philo->info->end = 0;
				usleep(100);
				ft_end_process(philo);
				return ;
			}
			if (philo->is_alive == 0 || philo->info->eating == 0)
				return ;
			philo = philo->next;
		}
	}
}

void	creat_threads(t_list *philo)
{
	int	i;

	i = 0;
	while (i++ < philo->info->num_of_philos)
	{
		pthread_mutex_init(&philo->fork, NULL);
		philo = philo->next;
	}
	pthread_mutex_init(&philo->info->write, NULL);
	i = 0;
	while (i++ < philo->info->num_of_philos)
	{
		philo->info->start = get_time();
		philo->num_of_eating = 0;
		philo->last_meal = 0;
		philo->total = 0;
		philo->died = philo->info->time_to_die;
		philo->is_alive = 1;
		philo->info->end = 1;
		philo->info->eating = 1;
		pthread_create(&philo->thread, NULL, routine, (void *)philo);
		usleep(60);
		philo = philo->next;
	}
}
