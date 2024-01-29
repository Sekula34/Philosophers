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
	
	if(philo_init(argc, argv, &philo) != 0)
		return(FAIL);
	printf("num of philos is %d\n", philo.num_of_philos);
	printf("die of philos is %ld\n", philo.time_to_die);
	printf("eat of philos is %ld\n", philo.time_to_eat);
	printf("sleep of philos is %ld\n", philo.time_to_sleep);
	printf("meals of philos is %d\n", philo.meals);
	return (OK);
	//init
	//philosophers_il_stagod
}