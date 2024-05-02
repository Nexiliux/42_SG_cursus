/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:17:31 by wchow             #+#    #+#             */
/*   Updated: 2024/04/13 17:42:26 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	ft_check_dupes(int *numbers, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc && argc > 1)
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
				exit(3);
			}
			j++;
		}
		i++;
	}
}

long	ft_strtol(const char *nptr)
{
	int	i;
	int	sign;
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

void	ft_check_size(char **arg)
{
	int	i;
	long	num;

	i = 0;
	while (arg[i])
	{
		num = ft_strtol(arg[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			ft_printf("Error\n");
			exit(2);
		}
		i++;
	}
}

void	ft_check_digit(char **arg)
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
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	*ft_parsing(int argc, char **argv, int *numbers)
{
	char	**arg;
	int	i;

	i = 0;
	arg = argv + 1;
	if ((ft_strncmp(argv[0], "./push_swap", 11)) != 0)
		arg = argv;
	ft_check_digit(arg);
	ft_check_size(arg);
	while (arg[i])
	{
		numbers[i] = ft_atoi(arg[i]);
		i++;
	}
	ft_check_dupes(numbers, argc - 1);

	return (numbers);
}
