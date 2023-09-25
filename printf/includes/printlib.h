/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:41:21 by wchow             #+#    #+#             */
/*   Updated: 2023/09/13 21:20:23 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIB_H
# define PRINTLIB_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char*, ...);
int	ft_checkconv(const char* str, va_list args);
int	pf_putstr(char *s);
int	pf_putnbr(int n);
int	pf_uputnbr(unsigned int n);
int	pf_hexadd(void *ptr);
int	pf_printhex(unsigned int n, const char *base)

#endif
