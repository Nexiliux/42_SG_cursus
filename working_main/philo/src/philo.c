/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:31:20 by wchow             #+#    #+#             */
/*   Updated: 2024/06/05 20:24:36 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor()
{
	//Check how long it's been for the philo since it has eaten
		//do this by using gettimeofday then minus the previous one, if
		//it's been longer than ttd, then kill the program.
}

void	*routine()
{
	//
}
int	init_philos(t_philo *philos, t_arg *arg, int i)
{
	while (++i < arg->philos)
	{
		philos[i].index = i + 1;
		philos[i].dead = 0;
		philos[i].lastmeal = gettimeofday(); //xf daddy say dong use gtod so much it not free bro
		philos[i].
	}
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
	
}
