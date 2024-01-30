/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:08 by fseles            #+#    #+#             */
/*   Updated: 2024/01/30 13:43:10 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *philo_func(void *pointer)
{
	t_philosophers *diogen;
	t_person *plato;


	diogen = (t_philosophers *)pointer;
	plato = diogen->person;
	printf("i am philosopher %d\n", plato->id);
	printf("my left fork is %d\n\n\n", plato->left_fork);
	return NULL;
}