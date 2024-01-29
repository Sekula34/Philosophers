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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char *) s1;
	sb = (unsigned char *) s2;
	i = 0;
	while ((n - i) > 0 && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (sa[i] != sb[i])
			return ((int)(sa[i] - sb[i]));
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int single_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
		{
			write(2, "Invalid input\n", 15);
			return(FAIL);
		}
		i++;
	}
	if (ft_strncmp(str, "2147483647", 10) > 0 && i > 9)
	{
		write(2, "Invalid input\n", 15);
		return (FAIL);
	}
	return (OK);
}

static int argv_checer(int argc, char **argv)
{
	int i; 

	i = 1;
	while(i < argc)
	{
		if(single_check((argv[i])) != 0)
			return (FAIL);
		i++;
	}
	return (OK);
}

int	input_checker(int argc, char **argv)
{
	(void) argv;
	if(argc < 5 || argc > 6)
	{
		write(2, "Program should take the following arguments\n", 45);
		write(2, "\ttime_to_die\n\ttime_to_eat\n\ttime_to_sleep\n", 42);
		write(2, "\t(in miliseconds)", 18);
		write(2, "\noptional arguments is number of meals", 39);
		return (FAIL);
	}
	if(argv_checer(argc, argv) != 0)
		return(FAIL);
	return (OK);
}
