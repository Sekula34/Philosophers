/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:01:22 by fseles            #+#    #+#             */
/*   Updated: 2024/01/29 18:01:23 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void destroy_and_free_forks(int amount_to_destroy, t_philosophers *philo)
{
	int i;
	i = 0;
	pthread_mutex_destroy(&philo->write_mut);
	pthread_mutex_destroy(&philo->meal_mut);
	while(i < amount_to_destroy)
	{
		pthread_mutex_destroy(&philo->fork_num[i]);
		i++;
	}
	free(philo->fork_num);
	return ;
}

static int init_forks(t_philosophers *philo)
{
	int i; 

	i = 0;
	while(i < philo->num_of_philos)
	{
		if(pthread_mutex_init(&philo->fork_num[i], NULL) != 0)
		{
			destroy_and_free_forks(i, philo);
			return (FAIL);
		}
		i++;
	}
	return (OK);
}

void philo_end(t_philosophers *philo)
{
	free(philo->person);
	free(philo->eaters);
	free(philo->eaters2);
	destroy_and_free_forks(philo->num_of_philos, philo);
}

int	mutex_init(t_philosophers *philo)
{
	philo->fork_num = malloc(sizeof(pthread_mutex_t) * philo->num_of_philos);
	if (philo->fork_num == NULL)
	{
		printf("malloc of mutex failed\n");
		return (FAIL);
	}
	if (pthread_mutex_init(&philo->write_mut, NULL) != 0)
	{
		printf("write mutex init failed \n");
		return (FAIL);
	}
	if (pthread_mutex_init(&philo->meal_mut, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->write_mut);
		printf("failed init");
		return (FAIL);
	}
	if (init_forks(philo) != 0)
		return (FAIL);
	return(OK);
}
