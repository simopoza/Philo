/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 06:21:47 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 04:07:59 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_list	*head;
	t_init	*t;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (0);
	t = (t_init *)malloc(sizeof(t_init));
	if (!t)
		return (0);
	if (ac <= 4 || ac > 6)
	{
		write (2, "Error\n", 7);
		return (0);
	}
	check_num(ac, av);
	head = linked_philos(head, ac, av, t);
	if (head == NULL)
		return (0);
	creat_threads(head);
	check_death(head);
	return (0);
}
