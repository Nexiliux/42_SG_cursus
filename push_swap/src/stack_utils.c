/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:06:54 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:03:54 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	stack_sorted(t_lst *a)
{
	if (a == NULL || a->next == NULL)
		return (1);
	while (a && a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	choose_sort(t_lst **a, t_lst **b)
{
	if (ft_lstsize2(*a) == 2)
		ra(a);
	else if (ft_lstsize2(*a) == 3)
		*a = sort_3(*a);
	else if (ft_lstsize2(*a) <= 5)
		sort_5(a, b);
	else if (ft_lstsize2(*a) <= 100)
		sort_stack(a, b, 21);
	else
		sort_stack(a, b, 50);
}
