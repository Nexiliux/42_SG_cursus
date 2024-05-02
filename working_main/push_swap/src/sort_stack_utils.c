/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:01:01 by wchow             #+#    #+#             */
/*   Updated: 2024/05/02 18:34:03 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	refresh(stack_node **node)
{
	int	i;
	stack_node	*head;

	i = -1;
	head = *node;
	while (head && ++i > -2)
	{
		head->index = i;
		if (head->index > ft_lstsize2(*node) / 2)
			head->above_mid = 1;
		else
			head->above_mid = 0;
		if (head->above_mid)
			head->move_price = ft_lstsize2(*node) - i + 1;
		else
			head->move_price = i;
		head = head->next;
	}
}

stack_node	*biggest(stack_node **node)
{
	stack_node	*temp;
	stack_node	*big;

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

stack_node	*smallest(stack_node **node)
{
	stack_node	*temp;
	stack_node	*smol;

	temp = *node;
	smol = *node;
	while (temp)
	{
		if (smol->num > temp->num)
			smol = temp;
		temp = temp->next;
	}
	return (smol);
}

void	action(stack_node *big, stack_node *smol, stack_node **a, stack_node **b)
{
	if (big->move_price < smol->move_price)
	{
		while (big->move_price-- > 0)
		{
			if (big->above_mid)
				rrb(b);
			else
				rb(b);
		}
		pa(a, b);
	}
	else
	{
		while (smol->move_price-- > 0)
		{
			if (smol->above_mid)
				rrb(b);
			else
				rb(b);
		}
		pa(a, b);
		ra(a);
	}
}
