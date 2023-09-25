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

int	ft_checkconv(const char *str, va_list args)
{
	int	count;
	char	c;

	count = 0;
	if (*str == 'c' || *str == '%')
	{
		c = va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (*str == 's')
		count += pf_putstr(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		count += pf_putnbr(va_arg(args, int));
	else if (*str == 'p')
		count += pf_hexadd(va_arg(args, void *));
	else if (*str == 'u')
		count += pf_uputnbr(va_arg(args, unsigned int));
	else if (*str == 'x')
		count += pf_printhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		count += pf_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		count += write(1, str, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	va_start (args, str);
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_checkconv(&str[i + 1, args);
			i++;
		}
		else
			count += write(1, str[i], 1);
		i++;
	}
	va_end (args);
	return (count);
}