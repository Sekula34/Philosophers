
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


filozofer_funkcija
{
	ako je filizofer neparan
		prva vilica = lijeva_vilica
		desna_vilica = desna_vilica
	ako je filozofer paran
		prva vilica = desna_vilica 
		druga vilica = lijeava_vilica
	while(i < broj_obroka)
	{
		uzmi_prvu_vilicu
		uzmi_drugu_vilicu
		papaj
		spavaj
		misli
	}
	return
}