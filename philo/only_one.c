/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:01:52 by fseles            #+#    #+#             */
/*   Updated: 2024/01/31 18:01:54 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	only_one(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->write_mut);
	printf("0 0 has taken a fork\n");
	printf("%ld 0 died\n", philo->time_to_die);
	pthread_mutex_unlock(&philo->write_mut);
}
