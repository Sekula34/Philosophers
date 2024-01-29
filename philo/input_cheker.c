/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cheker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:43:37 by fseles            #+#    #+#             */
/*   Updated: 2024/01/29 14:43:38 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_cheker(int argc, char **argv)
{
	(void) argv;
	if(argc < 5 || argc > 6)
	{
		write(2, "Program should take the following arguments\n", 45);
		write(2, "\ttime_to_die\n\ttime_to_eat\n\ttime_to_sleep\n", 42);
		write(2, "\t(in miliseconds)", 16);
		write(2, "\noptional arguments is number of meals", 38);
		return (FAIL);
	}
	return (OK);
}