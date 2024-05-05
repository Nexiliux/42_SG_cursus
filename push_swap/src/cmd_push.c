/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:30:55 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:53:00 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	push(t_lst **stack_give, t_lst **stack_take)
{
	t_lst	*head_from;
	t_lst	*head_to;
	t_lst	*head_temp;

	if (ft_lstsize2(*stack_give) == 0)
		return (-1);
	head_from = *stack_give;
	head_to = *stack_take;
	head_temp = *stack_give;
	head_from = head_from->next;
	*stack_give = head_from;
	if (!stack_take)
	{
		head_to = head_temp;
		head_to->next = NULL;
		*stack_take = head_to;
	}
	else
	{
		head_temp->next = head_to;
		*stack_take = head_temp;
	}
	return (0);
}

void	pa(t_lst **a, t_lst **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_lst **a, t_lst **b)
{
	push(a, b);
	ft_printf("pb\n");
}
