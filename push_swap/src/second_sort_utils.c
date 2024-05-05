/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:20:30 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:01:06 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

//The goal here is to find the biggest num in stack b then push over to stack a.

void	second_action(t_lst **a, t_lst **b)
{
	t_lst	*target;

	set_dex_price(b, ft_lstsize2(*b));
	target = big_to_push(b);
	while (target->move_price-- > 0)
	{
		if (target->above_mid)
			rrb(b);
		else
			rb(b);
	}
	pa(a, b);
}

t_lst	*big_to_push(t_lst **node)
{
	t_lst	*temp;
	t_lst	*big;

	temp = *node;
	big = *node;
	while (temp)
	{
		if (big->num < temp->num)
			big = temp;
		temp = temp->next;
	}
	return (big);
}
