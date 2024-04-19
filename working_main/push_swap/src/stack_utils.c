/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:06:54 by wchow             #+#    #+#             */
/*   Updated: 2024/04/19 23:08:47 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	stack_sorted(stack_node *a)
{
	if (a == NULL || a->next == NULL)
		return (1);
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (2);
		a = a->next;
	}
	return (1);
}