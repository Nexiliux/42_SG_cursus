/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:41:21 by wchow             #+#    #+#             */
/*   Updated: 2023/09/24 02:30:20 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printlib.h"

char	ft_checkconv(const char *str)
{
	char	type;
	
	type = '\0';
	str++;
	if (*str == 'c' || *str == 's' || *str == 'd' || *str == 'i' ||
		*str == 'p' || *str == 'u' || *str == 'x' || *str == 'X')
		type = *str;
	else
		return (0);
	return (type);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start (args, str);
	int	count;
	
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_checkconv(str) == 'c' || ft_checkconv(str) == '%')
			{
				write (1, str + 1, 1);
				count++;
			}
			else if (ft_checkconv(str) == 's')
				ft_putstr_fd(args, 1);
			else if (ft_checkconv(str) == 'p')
				ft_
			else if (ft_checkconv(str) == 'd' || ft_checkconv(str) == 'i')
				ft_
			else if (ft_checkconv(str) == 'u')
				ft_
			else if (ft_checkconv(str) == 'x')
				ft_
			else if (ft_checkconv(str) == 'X')
				ft_
		}
		else
		{
			write (1, str, 1);
			count++;
		}
		str++;
	}
	va_end (args);
	return (count);
}


