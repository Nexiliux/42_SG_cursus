/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:17:31 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:20:06 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	ft_check_dupes(int *numbers, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc)
		{
			if (j == i)
				j++;
			if (j > argc)
				break ;
			if (numbers[i] == numbers[j])
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
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

int	ft_check_size(char **arg)
{
	int		i;
	long	num;

	i = 0;
	while (arg[i])
	{
		num = ft_strtol(arg[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_digit(char **arg)
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
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_parsing(int elecount, char **split, int *numbers)
{
	int	i;

	i = 0;
	if (!ft_check_digit(split))
		return (0);
	if (!ft_check_size(split))
		return (0);
	while (split[i])
	{
		numbers[i] = ft_atoi(split[i]);
		i++;
	}
	if (!ft_check_dupes(numbers, elecount))
		return (0);
	return (numbers);
}
