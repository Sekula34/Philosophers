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


int main(int argc, char **argv)
{
	t_philosophers philo;
	//t_eater diogen;
	pthread_t *eaters;
	t_eater *platos;

	if(philo_init(argc, argv, &philo) != 0)
		return(FAIL);
	int i = 0;
	eaters = NULL;
	while (i < philo.num_of_philos)
	{
		printf("philo id is %d\n", philo.person[i].id);
		printf("dead flag is %d\n", philo.person[i].dead_flag);
		printf("last meal was %ld\n", philo.person[i].last_meal_time);
		printf("philo left_fork is %d\n", philo.person[i].left_fork);
		printf("philo right fork is %d\n\n", philo.person[i].right_fork);
		i++;
	}
	eaters = malloc(sizeof(pthread_t) * philo.num_of_philos);
	if(eaters == NULL)
	{
		philo_end(&philo);
		return (FAIL);
	}
	philo.eaters2 = eaters;
	platos =malloc(sizeof(t_eater) * philo.num_of_philos);
	if(platos == NULL)
	{
		philo_end(&philo);
		return (FAIL);
	}
	philo.eaters = platos;
	i = 0;
	while(i < philo.num_of_philos)
	{
		platos[i].philo =&philo;
		platos[i].person =philo.person + i;
		i++;
	}
	// diogen.philo = &philo;
	// diogen.person = philo.person;
	// diogen.id = 0;
	// void *pointer;
	// pointer = &diogen;
	i = 0;
	void *pointer;
	while (i < philo.num_of_philos)
	{
		pointer = (void *) (platos + i);
		pthread_create(&eaters[i], NULL, &philo_func, pointer);
		i++;
	}
	gravedigger(platos);
	i = 0;
	while (i < philo.num_of_philos)
	{
		pthread_join(eaters[i], NULL);
		i++;
	}
	printf("num of philos is %d\n", philo.num_of_philos);
	printf("die of philos is %ld\n", philo.time_to_die);
	printf("eat of philos is %ld\n", philo.time_to_eat);
	printf("sleep of philos is %ld\n", philo.time_to_sleep);
	printf("meals of philos is %d\n", philo.meals);
	philo_end(&philo);
	return (OK);
	//init
	//philosophers_il_stagod
}