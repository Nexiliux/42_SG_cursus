/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:43:46 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 19:16:18 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

stack_node	*sort_3(stack_node *a)
{
	if (a->num > a->next->num && a->num > a->next->next->num) //biggest on top
	{
		ra(&a);
		if (a->num > a->next->num) //swap if smallest not on top
			sa(&a);
	}
	else if (a->num < a->next->num && a->num < a->next->next->num) //smallest on top
	{
		sa(&a); //order is confirm 132, so just swap to 312 first
		ra(&a); //push up so it becomes 123;
	}
	else //order is either 213 or 231
	{
		if (a->num > a->next->num) //if it's 213
			sa(&a);
		else //if it's 231
			rra(&a);
	}
	return (a);
}
