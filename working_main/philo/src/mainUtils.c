/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:52:41 by wchow             #+#    #+#             */
/*   Updated: 2024/06/05 18:19:12 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	ft_atoi(char *arg, int result, int i)
{
	result += arg[i] - 48;
	i++;
	while (arg[i])
	{
		result *= 10;
		result += arg[i] - 48;
		i++;
	}
	return (result);
}

void	freedom(t_arg *arg)
{
	free(arg);
	exit(96);
}