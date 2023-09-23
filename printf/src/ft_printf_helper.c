/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:46:38 by wchow             #+#    #+#             */
/*   Updated: 2023/09/24 02:49:20 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"
#include "libft.h"

int	pf_putstr(char *s)
{
	int	count;

	count = 0;
	while (s++)
	{
		write (1, s, 1);
		count++;
	}
	return (count);
}

int	pf_putnbr(int	n)
{
	char	result;
	int	count;

	count = 0;
	if (n <= -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	result = (n % 10) + '0';
	write (fd, &result, 1);
	count++;
	return (count);
}


