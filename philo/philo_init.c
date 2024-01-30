/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:05:06 by fseles            #+#    #+#             */
/*   Updated: 2024/01/29 16:05:07 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return ((int)(result * sign));
}

//initialize evertyhint
//ok
//fail
int philo_init(int argc, char **argv, t_philosophers *philo)
{
	if(input_checker(argc, argv) != 0)
		return(FAIL);
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->start_time = get_time_in_milisec();
	philo->person = NULL;
	philo->meals = -1;
	if (argc == 6)
		philo->meals = ft_atoi(argv[5]);
	if(mutex_init(philo) != 0)
		return (FAIL);
	if(make_philos(philo) != 0)
	{
		philo_end(philo);
		return (FAIL);
	}
	return (OK);
}
