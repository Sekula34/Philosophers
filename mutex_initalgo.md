
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


neparan_filozofer_funkcija
{
	while(i < philo_meals)
		uzmi lijevu vilicu
		uzmi desnu vilicu
		papaj
		i++;
		pusti lijevu vilicu
		pusti desnu vilicu
		ako je pojeo meals puta break bez umiranja 
		spavaj
		misli
}