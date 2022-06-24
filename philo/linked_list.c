/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:40:29 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 02:40:46 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_list	*create_node(int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->num = data;
	return (tmp);
}

t_list	*add_at_empty(t_list *last, int data)
{
	t_list	*tmp;

	if (last != NULL)
		return (last);
	tmp = create_node(data);
	last = tmp;
	tmp->next = last;
	return (last);
}

t_list	*add_at_first(t_list *last, int data)
{
	t_list	*tmp;

	if (last == NULL)
		return (add_at_empty(last, data));
	tmp = create_node(data);
	tmp->next = last->next;
	last->next = tmp;
	return (last);
}
