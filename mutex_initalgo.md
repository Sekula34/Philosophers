
int mutex_init(t_philosopher philo)
{
	fork_num = malloc(sizeof(pthread_mutex_t) * philo.num_of_philos);
	ako je null
		CRITICAL 
	init_all_mutex
		ako fejla CRITICAL 
	write_mutex
		ako fejla critical
}

void philo_end
{
	//cekaj sve dretve
	unistavaj mutexe
	free mutexe
}