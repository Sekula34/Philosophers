/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:45:39 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 15:45:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//option 1 first fork
//option 2 second fork
static pthread_mutex_t *get_fork(t_eater *diogen, int id, int option)
{
	pthread_mutex_t *first;

	if(option == 2)
		id++;
	if(id % 2 == 1)
		first = &diogen->philo->fork_num[diogen->person->left_fork];
	else
		first =&diogen->philo->fork_num[diogen->person->right_fork];
	return(first);
}

void *philo_func(void *pointer)
{
	t_eater *diogen;
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	diogen = (t_eater *)pointer;
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("locakn\n");
	printf("ja sam diogen %d\n", diogen->person->id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	first_fork = get_fork(diogen, diogen->person->id, 1);
	second_fork = get_fork(diogen, diogen->person->id, 2);
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(second_fork);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("lockana prva vilica\n");
	printf("lockana i druga vilica\n");
	pthread_mutex_unlock(&diogen->philo->write_mut);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);

	return NULL;
}
