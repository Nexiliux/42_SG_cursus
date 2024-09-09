/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:31:20 by wchow             #+#    #+#             */
/*   Updated: 2024/08/17 13:08:57 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Monitoring thread
void	*monitor_thread(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	int	all_full;

	while (1)
	{
		all_full = 1;
		for (int i = 0; i < philos[0].arg->philos; i++)
		{
			t_philo *philo = &philos[i];

			pthread_mutex_lock(&philo->state); // Lock before reading state
			if (((get_cur_ms() - philo->lastmeal) > philo->arg->ttd))
			{
				//printf("%d\n", philo->arg->eatnum);
				philo->dead = 1;
				*philo->exit = 1;
				printf("MONITOR: Philo %d has died.[%d]\n", philo->index, timestamp(philo->startms));
				pthread_mutex_unlock(&philo->state); // Unlock after reading state
				return NULL; // Terminate monitoring thread or take appropriate action
			}
			if (philo->arg->eatnum != 0 && philo->eatnum != philo->arg->eatnum)
				all_full = 0;
			if (philo->arg->eatnum == 0)
				all_full = 0;
			pthread_mutex_unlock(&philo->state); // Unlock after reading state
		}
		if (all_full)
		{
			printf("MONITOR: All philosophers have finished their meals.\n");
			break ;
		}
		usleep(1000); // Small delay to prevent busy waiting
	}
	exit(0);
}

// Thread function for each philosopher
void	*philosopher_thread(void *arg) {
	t_philo *philo = (t_philo *)arg;
	printf("Philosopher %d started\n", philo->index);
	// Here you can add the philosopher's actions
	while (1 && *philo->exit != 1)
	{
		if (*philo->exit == 1)
			break ;
		printf("Philosopher %d is thinking.[%d]\n", philo->index, timestamp(philo->startms));

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
		
		if (*philo->exit == 1)
			break ;
		//Eat after trying to lock both mutexes
		pthread_mutex_lock(&philo->state);
		printf("Philosopher %d is eating.[%d]\n", philo->index, timestamp(philo->startms));
		philo->lastmeal = get_cur_ms();
		usleep (1000 * philo->arg->tte);
		pthread_mutex_unlock(&philo->state);
		philo->eatnum++;

		//Forks down
		pthread_mutex_unlock (philo->right_fork);
		pthread_mutex_unlock (philo->left_fork);

		if (*philo->exit == 1)
			break ;
		//Time to orh orh
		printf("Philosopher %d is sleeping.[%d]\n", philo->index, timestamp(philo->startms));
		usleep (1000 * philo->arg->tts);

		//Check Fullness
		if (philo->eatnum != 0 && philo->eatnum == philo->arg->eatnum)
		{
			printf("Philo %d finished lifecycle.[%d]\n", philo->index, timestamp(philo->startms));
			break;
		}
		//Check Death
		pthread_mutex_lock(&philo->state);
		if ((get_cur_ms() - philo->lastmeal) > philo->arg->ttd)
		{
			philo->dead = 1;
			philo->debugLastMeal = get_cur_ms() - philo->lastmeal;
			printf("Philo %d has died. Lastmeal: %dms| TTD: %d[%d]\n",
				philo->index, philo->debugLastMeal, philo->arg->ttd, timestamp(philo->startms));
			pthread_mutex_unlock(&philo->state);
			break;
		}
		pthread_mutex_unlock(&philo->state);
	}
	return NULL;
}



void join_philos(t_philo *philos, int num_philos) {
	int i = 0;
	while (i < num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	init_philos(t_philo *philos, t_arg *arg, int i)
{
	long	currms = get_cur_ms();
	int     *exit = malloc(sizeof(int));
	*exit = 0;

	pthread_mutex_t *forks = malloc(sizeof(pthread_mutex_t) * arg->philos);
	if (!forks)
	{
		perror("Failed to allocate memory for forks");
		return -1;
	}

	while (++i < arg->philos)
	{
		philos[i].index = i + 1;
		philos[i].dead = 0;
		philos[i].lastmeal = currms; //xf daddy say dong use gtod so much it not free bro
		philos[i].startms = currms;
		philos[i].eatnum = 0;
		philos[i].debugLastMeal = 0;
		philos[i].exit = exit;
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

int	timestamp(int startms)
{
	return (get_cur_ms() - startms);
}

int	main(int argc, char **argv)
{
	t_arg	*arg;
	t_philo	*philos;
	pthread_t monitor;
	
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

	//Creating philos
	philos = malloc(sizeof(t_philo) * arg->philos);
	init_philos(philos, arg, -1);

	//Creating Monitoring thread
	pthread_create(&monitor, NULL, monitor_thread, (void *)philos);	

	join_philos(philos, arg->philos);
	pthread_join(monitor, NULL);
	for (int i = 0; i < arg->philos; i++)
		printf("Philo id: %d| Dead? %d| Lastmeal: %dms| Times ate: %d\n", philos[i].index,
			philos[i].dead, philos->debugLastMeal, philos[i].eatnum);
	printf("Program completed[%d]\n", timestamp(philos->startms));
}
