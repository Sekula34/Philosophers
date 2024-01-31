/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:29:48 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 19:29:49 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//1 continue sim
//0 end sim
int	sleeping(t_eater *diogen)
{
	int	id;

	id = diogen->person->id;
	if (am_i_dead(diogen, 0) == 1)
		return (0);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d is sleeping\n", get_relative_time(diogen), id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	usleep(diogen->philo->time_to_sleep * MILI);
	if (am_i_dead(diogen, 0) == 1)
		return (0);
	pthread_mutex_lock(&diogen->philo->write_mut);
	printf("%ld %d is thinking\n", get_relative_time(diogen), id);
	pthread_mutex_unlock(&diogen->philo->write_mut);
	usleep(100);
	return (1);
}
