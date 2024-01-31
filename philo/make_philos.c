/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:56:22 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 10:56:23 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	get_time_in_milisec(void)
{
	struct timeval	my_time;
	time_t			mili_time;

	mili_time = 0;
	if (gettimeofday(&my_time, NULL) != 0)
	{
		printf("gettimeofday in set milisec failed\n");
		return (mili_time);
	}
	mili_time = (my_time.tv_sec * 1000) + (my_time.tv_usec / 1000);
	return (mili_time);
}

//nop is number of philos
void	one_philo_init(t_person *person, int id, int nop)
{
	person->id = id;
	person->dead_flag = 0;
	person->left_fork = id;
	person->right_fork = id - 1;
	person->number_of_meals = 0;
	if (id == 0)
		person->right_fork = nop - 1;
	person->last_meal_time = get_time_in_milisec();
}

//make and initilize person of philos
//0 ok 
//1 Fail
int	make_philos(t_philosophers *philo)
{
	int	i;

	i = 0;
	philo->person = malloc(sizeof(t_person) * philo->num_of_philos);
	if (philo->person == NULL)
		return (FAIL);
	while (i < philo->num_of_philos)
	{
		one_philo_init(&philo->person[i], i, philo->num_of_philos);
		i++;
	}
	return (OK);
}
