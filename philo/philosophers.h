/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:31:55 by mannahri          #+#    #+#             */
/*   Updated: 2022/06/23 03:17:19 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct philosophers
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times;
	int				end;
	int				eating;
	long int		start;
	pthread_mutex_t	write;
}	t_init;

typedef struct node
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				num;
	int				is_alive;
	int				total;
	int				died;
	int				num_of_eating;
	struct node		*next;
	long			last_meal;
	t_init			*info;
}	t_list;

int			main(int ac, char **av);
int			ft_atoi(const char *str);
void		check_num(int ac, char **av);
t_list		*add_at_first(t_list *last, int data);
t_init		*initial_philos(int ac, char **av, t_init *t);
t_list		*linked_philos(t_list *head, int ac, char *av[], t_init *t);
void		creat_threads(t_list *list);
void		ft_sleep(long int timming);
void		check_death(t_list *philo);
long int	get_time(void);
int			ft_isdigit(int c);
void		ft_write_philo(void *list, int i);

#endif