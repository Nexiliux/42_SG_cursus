/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:45:52 by wchow             #+#    #+#             */
/*   Updated: 2024/06/13 18:42:07 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

//Argument Variables
typedef struct s_arg
{
	int	philos;
	int	ttd;
	int	tte;
	int	tts;
	int	eatnum;

}	t_arg;

//Philo stats
typedef struct s_philo
{
	int	index;
	int	dead;
	long	lastmeal;
	int	eatnum;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t thread;
	t_arg *arg;
}	t_philo;

/* typedef struct s_fork
{
	int	index;
	int	inuse;
}	t_fork; */

//Input Checking
int	inputcheck(int argc, char **argv);
long	ft_strtol(const char *nptr);
int	check_size(char **arg);
int	check_digit(char **arg);
int	ft_isdigit(char c);

//Initialisation
int	initialisation(t_arg *arg, int argc, char **argv);
int	ft_atoi(char *arg, int result, int i);

//Utilities
void	freedom(t_arg *arg);
long	get_cur_ms();

#endif