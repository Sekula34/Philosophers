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

//1 continue sim
//0 end sim
int eating_func(t_eater *diogen)
{
	int id;

	id = diogen->person->id;
	if(am_i_dead(diogen, 0) == 1)
		return (0);
	pthread_mutex_lock(diogen->first_fork);
	if(am_i_dead(diogen, 1) == 1)
		return (0);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d has taken a fork\n", get_relative_time(diogen), id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	pthread_mutex_lock(diogen->second_fork);
	if(am_i_dead(diogen, 2) == 1)
		return (0);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d has taken a fork\n", get_relative_time(diogen), id);
	printf("%ld %d is eating\n", get_relative_time(diogen), id);
	pthread_mutex_lock(&diogen->philo->meal_mut);
	diogen->person->last_meal_time = get_time_in_milisec();
	diogen->person->number_of_meals++;
	pthread_mutex_unlock(&diogen->philo->meal_mut);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	usleep(diogen->philo->time_to_eat * 1000);
	pthread_mutex_unlock(diogen->first_fork);
	pthread_mutex_unlock(diogen->second_fork);
	//printf("%ld %d pustene vilice fork\n", get_relative_time(diogen), id);
	if(am_i_dead(diogen, 0) == 1)
		return (0);
	return (1);
}
