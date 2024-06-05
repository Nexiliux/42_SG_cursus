/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:52:44 by wchow             #+#    #+#             */
/*   Updated: 2024/06/05 18:44:33 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	inputcheck(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error.\nYou can only input 5 or 6 arguments\n");
		return (0);
	}
	if (!check_digit(argv))
	{
		printf("Error.\nYou can only input numbers\n");
		return (0);
	}
	if (!check_size(argv))
	{
		printf("Error.\nKeep within INTMAX & only positive numbers\n");
		return (0);
	}
	return (1);
}

long	ft_strtol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' && !(nptr[i] >= '0' && nptr[i] <= '9'))
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_size(char **arg)
{
	int		i;
	long	num;

	i = 0;
	while (arg[i])
	{
		num = ft_strtol(arg[i]);
		if (num < 0 || num > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_digit(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (ft_isdigit(arg[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}