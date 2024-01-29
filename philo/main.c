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
	pthread_mutex_t kljuc;

void *my_thread(void *argp)
{
	int value; 
	value = *(int *)argp;
	pthread_mutex_lock(&kljuc);
	printf("cao ja sam dretva, %d \n", value);
	pthread_mutex_unlock(&kljuc);
	return NULL;
}

int main()
{
	struct timeval my_time;
	pthread_t first_thread;
	int value_maiin = 2;



	if(pthread_mutex_init(&kljuc, NULL) != 0)
		return(perror("pao init"), FAIL);
	void *v_p;

	v_p = &value_maiin;
	if(gettimeofday(&my_time, NULL) != 0)
	{
		perror("gettimeofday failed");
		return (FAIL);
	}
	pthread_mutex_lock(&kljuc);
	printf("trenutno vrijeme je %ld sekundi i %ld mikrosekundi\n", my_time.tv_sec, my_time.tv_usec);
	pthread_mutex_unlock(&kljuc);
	if(pthread_create(&first_thread, NULL, &my_thread, v_p) != 0)
		return (FAIL);
	//if(pthread_detach(first_thread) != 0)
		//return (perror("fail"), FAIL);
	if(pthread_join(first_thread, NULL) != 0)
		return(perror("spoj je faileo"), FAIL);
	printf("spojeni smo\n");
	//printf("Dretva otkacena\n");
	usleep(5 * MICRO);
	if(gettimeofday(&my_time, NULL) != 0)
	{
		perror("gettimeofday failed");
		return (FAIL);
	}
	printf("trenutno vrijeme je %ld sekundi i %ld mikrosekundi\n", my_time.tv_sec, my_time.tv_usec);
	printf("hello i am filip\n");
	pthread_mutex_destroy(&kljuc);
	return(OK);
}