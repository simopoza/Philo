/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 06:17:27 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 02:27:46 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	rus;
	int	i;

	rus = 0;
	i = 0;
	if (!ft_isdigit(*str))
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rus = (rus * 10) + (str[i] - 48);
		i++;
	}
	return (rus);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	is_number(char num[])
{
	int	i;

	i = 0;
	if (!num[0])
		return (false);
	if ((num[0] == '-' || num[0] == '+') && num[1] != '\0')
		i = 1;
	while (num[i] != 0)
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

void	check_num(int ac, char **av)
{
	int	i;

	i = ac;
	while (i-- > 1)
	{
		if (!is_number(av[--ac]))
		{
			printf("is not digit\n");
			exit(0);
		}
	}
}
