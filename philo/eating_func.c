/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:17:18 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 18:17:19 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eating_func(t_eater *diogen)
{
	int id;

	id = diogen->person->id;
	pthread_mutex_lock(diogen->first_fork);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d has taken a fork\n", get_relative_time(diogen), id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	pthread_mutex_lock(diogen->second_fork);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d has taken a fork\n", get_relative_time(diogen), id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	

	diogen->person->last_meal_time = get_time_in_milisec();

}