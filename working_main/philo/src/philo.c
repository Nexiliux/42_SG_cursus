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
	while (++i < arg->philos)
	{
		philos[i].index = i + 1;
		philos[i].dead = 0;
		philos[i].lastmeal = currms; //xf daddy say dong use gtod so much it not free bro
		philos[i].fork = 0;
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
	printf("Elapsed time: %ld milliseconds\n", mseconds);
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
	printf("Number of Philos: %d\n", arg->philos);
	printf("Time till death: %d\n", arg->ttd);
	printf("Time to eat: %d\n", arg->tte);
	printf("Sleep Length: %d\n", arg->tts);
	printf("Max eat times: %d\n", arg->eatnum);
	philos = malloc(sizeof(t_philo) * arg->philos);
	init_philos(philos, arg, -1);
	join_philos(philos, arg->philos);
	for (int i = 0; i < arg->philos; i++)
	{
		printf("Philo id: %d\n", philos[i].index);
		printf("Philo dead?: %d\n", philos[i].dead);
		printf("Philo lastmeal: %ldms\n", get_cur_ms() - philos[i].lastmeal);
		printf("Philo fork: %d\n", philos[i].fork);
	}
}
