/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:37:31 by wchow             #+#    #+#             */
/*   Updated: 2024/06/05 18:40:42 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialisation(t_arg *arg, int argc, char **argv)
{
	arg->philos = ft_atoi(argv[0], 0, 0);
	arg->ttd = ft_atoi(argv[1], 0, 0);
	arg->tte = ft_atoi(argv[2], 0, 0);
	arg->tts = ft_atoi(argv[3], 0, 0);
	if (argc == 6)
		arg->eatnum = ft_atoi(argv[4], 0, 0);
	else
		arg->eatnum = 0;
	return (1);
}