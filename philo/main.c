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

//return number of thread
int thread_creation(t_philosophers *philo, t_eater *platos, pthread_t *eaters)
{
	int i;
	void *pointer;

	i = 0;
	while (i < philo->num_of_philos)
	{
		pointer = (void *) (platos + i);
		if (pthread_create(&eaters[i], NULL, &philo_func, pointer) !=0)
			return (i);
		i++;
	}
	return (i);
}

//0 return ok 
//1 return fail
//2 continu
int first_part(t_philosophers *philo, int argc, char **argv, pthread_t **eaters)
{
	if (philo_init(argc, argv, philo) != 0)
		return (FAIL);
	*eaters = NULL;
	if (philo->num_of_philos == 1)
		return (only_one(philo),philo_end(philo), OK);
	return (2);
}

void end_part(int t_number, t_eater *platos, pthread_t *eaters, t_philosophers *philo)
{
	int thread_number;
	int i;

	thread_number = t_number;
	gravedigger(platos);
	i = 0;
	while (i < thread_number)
	{
		pthread_join(eaters[i], NULL);
		i++;
	}
	philo_end(philo);
}

int main(int argc, char **argv)
{
	t_philosophers philo;
	pthread_t *eaters;
	t_eater *platos;
	int thread_number;

	int i = 0;
	if(first_part(&philo, argc, argv, &eaters) != 2)
		return (OK);
	eaters = malloc(sizeof(pthread_t) * philo.num_of_philos);
	if (eaters == NULL)
		return (philo_end(&philo),FAIL);
	philo.eaters2 = eaters;
	platos = malloc(sizeof(t_eater) * philo.num_of_philos);
	if (platos == NULL)
		return (philo_end(&philo), FAIL);
	philo.eaters = platos;
	i = 0;
	while(i < philo.num_of_philos)
	{
		platos[i].philo = &philo;
		platos[i].person = philo.person + i;
		i++;
	};
	thread_number = thread_creation(&philo, platos, eaters);
	return (end_part(thread_number, platos, eaters, &philo),OK);
}
