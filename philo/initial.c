/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:38:48 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 04:07:11 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_init	*ft_help_initial_philos(int ac, char **av, t_init *t)
{
	(void)ac;
	t->time_to_sleep = ft_atoi(av[4]);
	if (t->time_to_sleep == -1)
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	t->num_of_times = 0;
	if (ac == 6)
	{
		t->num_of_times = ft_atoi(av[5]);
		if (t->num_of_times == -1)
		{
			write(2, "Error\n", 7);
			return (NULL);
		}
	}
	return (t);
}

t_init	*initial_philos(int ac, char **av, t_init *t)
{
	t->num_of_philos = ft_atoi(av[1]);
	if (t->num_of_philos == -1)
	{
		write (2, "Error\n", 7);
		return (NULL);
	}
	t->time_to_die = ft_atoi(av[2]);
	if (t->time_to_die == -1)
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	t->time_to_eat = ft_atoi(av[3]);
	if (t->time_to_eat == -1)
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	t = ft_help_initial_philos(ac, av, t);
	return (t);
}

t_list	*linked_philos(t_list *head, int ac, char *av[], t_init *t)
{
	t_list	*last;
	int		i;
	int		count;

	last = NULL;
	i = ft_atoi(av[1]);
	count = ft_atoi(av[1]);
	if (count == -1 || count == 0)
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	while (count--)
		last = add_at_first(last, i--);
	head = last->next;
	i = ft_atoi(av[1]);
	while (i--)
	{
		head->info = initial_philos(ac, av, t);
		if (head->info == NULL)
			return (NULL);
		free(head);
		head = head->next;
	}
	return (head);
}
