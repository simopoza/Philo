/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:58:53 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 02:37:45 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_time(void)
{
	long int		time;
	struct timeval	mytime;

	if (gettimeofday(&mytime, NULL) == -1)
		return (0);
	time = (mytime.tv_sec * 1000) + (mytime.tv_usec / 1000);
	return (time);
}

void	ft_sleep(long timming)
{
	long	time;

	time = get_time();
	while (get_time() - time < timming)
		usleep(100);
}
