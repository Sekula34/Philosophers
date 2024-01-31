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
	pthread_t *eaters;
	t_eater *platos;
	int thread_number;

	if (philo_init(argc, argv, &philo) != 0)
		return (FAIL);
	int i = 0;
	eaters = NULL;
	if (philo.num_of_philos == 1)
		return (only_one(&philo),philo_end(&philo), OK);
	eaters = malloc(sizeof(pthread_t) * philo.num_of_philos);
	if (eaters == NULL)
		return (philo_end(&philo),FAIL);
	philo.eaters2 = eaters;
	platos = malloc(sizeof(t_eater) * philo.num_of_philos);
	if(platos == NULL)
		return (philo_end(&philo), FAIL);
	philo.eaters = platos;
	i = 0;
	while(i < philo.num_of_philos)
	{
		platos[i].philo = &philo;
		platos[i].person =philo.person + i;
		i++;
	};
	i = 0;
	void *pointer;
	while (i < philo.num_of_philos)
	{
		pointer = (void *) (platos + i);
		if(pthread_create(&eaters[i], NULL, &philo_func, pointer) !=0)
			break;
		i++;
	}
	thread_number = i;
	gravedigger(platos);
	i = 0;
	while (i < thread_number)
	{
		pthread_join(eaters[i], NULL);
		i++;
	}
	philo_end(&philo);
	return (OK);
}
