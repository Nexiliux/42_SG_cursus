/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:31:20 by wchow             #+#    #+#             */
/*   Updated: 2024/06/13 18:43:37 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	*monitor()
{
	//Check how long it's been for the philo since it has eaten
		//do this by using gettimeofday then minus the previous one, if
		//it's been longer than ttd, then kill the program.
} */

// Thread function for each philosopher
void	*philosopher_thread(void *arg) {
	t_philo *philo = (t_philo *)arg;
	printf("Philosopher %d started\n", philo->index);
	// Here you can add the philosopher's actions
	while (1)
	{
		printf("Philosopher %d is thinking.\n", philo->index);
		if (philo->index % 2 == 0)
		{
			pthread_mutex_lock (philo->left_fork);
			pthread_mutex_lock (philo->right_fork);
		}
		else
		{
			pthread_mutex_lock (philo->right_fork);
			pthread_mutex_lock (philo->left_fork);
		}
		
		//Eat after trying to lock both mutexes
		printf("Philosopher %d is eating.\n", philo->index);
		philo->lastmeal = get_cur_ms();
		usleep (1000 * philo->arg->tte);
		philo->eatnum++;

		//Forks down
		pthread_mutex_unlock (philo->right_fork);
		pthread_mutex_unlock (philo->left_fork);

		//Time to orh orh
		printf("Philosopher %d is sleeping.\n", philo->index);
		usleep (1000 * philo->arg->tts);

		if (philo->eatnum != 0 && philo->eatnum == philo->arg->eatnum)
			break;
	}
	printf("Philo finished lifecycle.\n");
	return NULL;
}



void join_philos(t_philo *philos, int num_philos) {
    for (int i = 0; i < num_philos; i++) {
        pthread_join(philos[i].thread, NULL);
    }
}

int	init_philos(t_philo *philos, t_arg *arg, int i)
{
	long	currms = get_cur_ms();


	pthread_mutex_t forks[arg->philos];
	for (int i = 0; i < arg->philos; i++)
		pthread_mutex_init(&forks[i], NULL);

	while (++i < arg->philos)
	{
		philos[i].index = i + 1;
		philos[i].dead = 0;
		philos[i].lastmeal = currms; //xf daddy say dong use gtod so much it not free bro
		philos[i].eatnum = 0;
		philos[i].arg = arg;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % arg->philos];
		if (pthread_create(&philos[i].thread, NULL, philosopher_thread, &philos[i]) != 0)
		{
			perror("Failed to create thread");
			return -1;
		}
	}
	return (0);
}

long	get_cur_ms()
{
	struct timeval	ms;
	long	seconds;
	long	useconds;
	long	mseconds;

	gettimeofday(&ms, NULL);
	seconds  = ms.tv_sec;
	useconds = ms.tv_usec;
	mseconds = (seconds * 1000) + (useconds / 1000);
	//printf("Elapsed time: %ld milliseconds\n", mseconds);
	return (mseconds);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_philo	*philos;
	
	argv = argv + 1;
	if (!inputcheck(argc, argv))
		exit(69);
	arg = malloc(sizeof(t_arg));
	if (!initialisation(arg, argc, argv))
		freedom(arg);
	printf("Number of Philo & fox: 	%d\n", arg->philos);
	printf("Time till death: 	%d (ms)\n", arg->ttd);
	printf("Time to eat:		%d (ms)\n", arg->tte);
	printf("Sleep Length: 		%d (ms)\n", arg->tts);
	printf("Max eat times: 		%d\n", arg->eatnum);
	philos = malloc(sizeof(t_philo) * arg->philos);
	
	init_philos(philos, arg, -1);
	join_philos(philos, arg->philos);
	for (int i = 0; i < arg->philos; i++)
	{
		printf("Philo id: %d\n", philos[i].index);
		printf("Philo dead?: %d\n", philos[i].dead);
		printf("Philo lastmeal: %ldms\n", get_cur_ms() - philos[i].lastmeal);
	}
}
