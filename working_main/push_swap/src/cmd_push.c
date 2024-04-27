/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:30:55 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 17:21:21 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	push(stack_node **stack_give, stack_node **stack_take)
{
	stack_node	*head_from;
	stack_node	*head_to;
	stack_node	*head_temp;

	if (ft_lstsize2(*stack_give) == 0)
		return (-1);
	head_from = *stack_give; //setting stack to give
	head_to = *stack_take; //setting stack to take
	head_temp = *stack_give; //setting temp to giver 
	head_from = head_from->next;
	*stack_give = head_from; //set giver's head to the next in line
	if (!stack_take) //if the taker is empty
	{
		head_to = head_temp; //set moving node to be the head of the giver
		head_to->next = NULL; //set the next node to be NULL cos it was empty 
		*stack_take = head_to; //update original stack to point to new node
	}
	else //if taker isn't empty
	{
		head_temp->next = head_to; //to move the temp infront of the taker's head
		*stack_take = head_temp; //update taking stack to point to temp
	}
	return (0);
}

void	pa(stack_node **a, stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(stack_node **a, stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
