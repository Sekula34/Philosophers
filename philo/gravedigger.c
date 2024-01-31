/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gravedigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:21:50 by fseles            #+#    #+#             */
/*   Updated: 2024/01/31 11:21:51 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void kill_all_protected(t_eater *diogen, int not)
{
	(void) diogen;
	int i;
	t_eater *first;

	first = diogen;

	i = 0;
	while(i < not)
	{
		first = diogen + i;
		first->person->dead_flag = 1;
		i++;
	}
}

void kill_all(t_eater *diogen)
{
	(void) diogen;
	int i;
	t_eater *first;

	first = diogen;

	i = 0;
	pthread_mutex_lock(&diogen->philo->meal_mut);
	while(i < diogen->philo->num_of_philos)
	{
		first = diogen + i;
		first->person->dead_flag = 1;
		i++;
	}
	pthread_mutex_unlock(&diogen->philo->meal_mut);
}

//1 philosopher is dead
//0 philosopher is still alive
int	is_dead(t_eater *diogen)
{
	time_t last_meal;
	time_t current;
	time_t difference;
	time_t time_to_die;

	pthread_mutex_lock(&diogen->philo->meal_mut);
	last_meal = diogen->person->last_meal_time;
	time_to_die = diogen->philo->time_to_die;
	pthread_mutex_unlock(&diogen->philo->meal_mut);
	current = get_time_in_milisec();
	difference = current - last_meal;
	//printf("difference is %ld, time to die is %ld, current time is %ld, last meal time is %ld\n", difference, time_to_die, current, last_meal);
	if(difference > time_to_die)
	{
		pthread_mutex_lock(&diogen->philo->meal_mut);
		diogen->person->dead_flag = 1;
		diogen->philo->stop_simulation = 1;
		pthread_mutex_unlock(&diogen->philo->meal_mut);
		pthread_mutex_lock(&diogen->philo->write_mut);
		if(diogen->person->number_of_meals != diogen->philo->meals)
			printf("%ld %d died\n", get_relative_time(diogen), diogen->person->id);
		pthread_mutex_unlock(&diogen->philo->write_mut);
		return (1);
	}
	return(0);
}

void gravedigger(t_eater *diogen)
{
	t_eater *current;
	t_eater *first;

	int i;

	i = 0;
	first = diogen;
	current = first;
	while(1)
	{
		if(i + 1 == diogen->philo->num_of_philos)
			i = 0;
		if(is_dead(diogen + i) == 1)
		{
			kill_all(first);
			return ;
		}
		i++;
	}
}
