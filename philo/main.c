/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:23:23 by fseles            #+#    #+#             */
/*   Updated: 2024/01/26 15:23:25 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex1;

int main(int argc, char **argv)
{
	t_philosophers philo;
	pthread_mutex_t *mutex_num; 

	printf("mutex1 is initialized\n");
	if(philo_init(argc, argv, &philo) != 0)
		return(FAIL);
	if(mutex_init(&philo) != 0)
		return(FAIL);
	printf("num of philos is %d\n", philo.num_of_philos);
	printf("die of philos is %ld\n", philo.time_to_die);
	printf("eat of philos is %ld\n", philo.time_to_eat);
	printf("sleep of philos is %ld\n", philo.time_to_sleep);
	printf("meals of philos is %d\n", philo.meals);
	mutex_num = malloc(sizeof(pthread_mutex_t) * philo.num_of_philos);
	if(mutex_num == NULL)
	{
		printf("malloc of mutexes failed");
		philo_end(&philo);
		return (FAIL);
	}
	pthread_mutex_init(&mutex_num[0], NULL);
	pthread_mutex_lock(&mutex_num[0]);
	printf("mutexes are created\n");
	pthread_mutex_unlock(&mutex_num[0]);
	pthread_mutex_destroy(&mutex_num[0]);
	free(mutex_num);
	philo_end(&philo);
	return (OK);
	//init
	//philosophers_il_stagod
}