/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:51:30 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 02:54:15 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_help_write_philo(t_list *philo, int i)
{
	if (i == 3 && philo->info->end)
	{
		pthread_mutex_lock(&philo->info->write);
		printf("%ld philo %d is sleeping\n", \
		get_time() - philo->info->start, philo->num);
		pthread_mutex_unlock(&philo->info->write);
	}
	if (i == 4 && philo->info->end)
	{
		pthread_mutex_lock(&philo->info->write);
		printf("%ld philo %d is thinking\n", \
		get_time() - philo->info->start, philo->num);
		pthread_mutex_unlock(&philo->info->write);
	}
}

void	ft_write_philo(void *list, int i)
{
	t_list	*philo;

	philo = (t_list *)list;
	if (i == 1 && philo->info->end)
	{
		pthread_mutex_lock(&philo->info->write);
		printf("%ld philo %d take a fork\n", \
		get_time() - philo->info->start, philo->num);
		pthread_mutex_unlock(&philo->info->write);
	}
	if (i == 2 && philo->info->end)
	{
		pthread_mutex_lock(&philo->info->write);
		printf("%ld philo %d is eating\n", \
		get_time() - philo->info->start, philo->num);
		pthread_mutex_unlock(&philo->info->write);
	}
	ft_help_write_philo(philo, i);
}
