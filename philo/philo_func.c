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

void *philo_func(void *pointer)
{
	t_eater *diogen;

	diogen = (t_eater *)pointer;
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("locakn\n");
	printf("ja sam diogen %d\n", diogen->person->id);
	pthread_mutex_unlock(&diogen->philo->write_mut);

	return NULL;
}