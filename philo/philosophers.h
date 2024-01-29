/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:02 by fseles            #+#    #+#             */
/*   Updated: 2024/01/26 15:23:04 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define OK 0
# define FAIL 1
# define MICRO 1000000
# define MILI 1000

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosophers
{
	int		num_of_philos;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		meals;
	pthread_mutex_t *fork_num;
	pthread_mutex_t write_mut;
} t_philosophers;

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	input_checker(int argc, char **argv);
int	mutex_init(t_philosophers *philo);
void philo_end(t_philosophers *philo);
int philo_init(int argc, char **argv, t_philosophers *philo);

#endif
