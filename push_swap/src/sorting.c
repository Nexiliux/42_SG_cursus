/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:43:46 by wchow             #+#    #+#             */
/*   Updated: 2024/05/24 14:42:06 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	sort_stack(t_lst **a, t_lst **b, int gcount)
{
	while (*a)
	{
		set_gmedian(a, gcount);
		first_action(a, b, gcount);
	}
	while (*b)
	{
		second_action(a, b);
	}
}

t_lst	*sort_3(t_lst *a)
{
	if (a->num > a->next->num && a->num > a->next->next->num)
	{
		ra(&a);
		if (a->num > a->next->num)
			sa(&a);
	}
	else if (a->num < a->next->num && a->num < a->next->next->num)
	{
		if (a->next->num > a->next->next->num)
		{
			sa(&a);
			ra(&a);
		}
	}
	else
	{
		if (a->num > a->next->num)
			sa(&a);
		else
			rra(&a);
	}
	return (a);
}

void	sort_5(t_lst **a, t_lst **b)
{
	set_gmedian(a, 2);
	first_action(a, b, 2);
	*a = sort_3(*a);
	if (stack_sorted(*b))
		sb(b);
	while (ft_lstsize2(*b) > 0)
		pa(a, b);
}
