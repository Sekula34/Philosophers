/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:29:10 by fseles            #+#    #+#             */
/*   Updated: 2024/01/31 13:29:13 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//check if eater is dad 
//if it is return 1 and unlock number of taken mutexes from number of mutexes
int	am_i_dead(t_eater *diogen, int number_of_mutex)
{
	int	status;

	status = 0;
	pthread_mutex_lock(&diogen->philo->meal_mut);
	if (diogen->person->dead_flag == 1)
		status = 1;
	pthread_mutex_unlock(&diogen->philo->meal_mut);
	if (status == 0)
		return (0);
	if (number_of_mutex == 0)
		return (1);
	if (number_of_mutex == 1)
	{
		pthread_mutex_unlock(diogen->first_fork);
		return (1);
	}
	if (number_of_mutex == 2)
	{
		pthread_mutex_unlock(diogen->first_fork);
		pthread_mutex_unlock(diogen->second_fork);
		return (1);
	}
	return (0);
}
