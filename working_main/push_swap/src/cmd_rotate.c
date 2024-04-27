/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:35 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 18:49:05 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time. */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	rotate(stack_node **stack)
{
	stack_node	*head;
	stack_node	*tail;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack; //setting head
	tail = ft_lstlast2(*stack); //setting tail
	*stack = head->next; //top of stack is now the 2nd element
	tail->next = head; //moving head to the last element
	head->next = NULL; //closing the tail
	return (0);
}

void	ra(stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(stack_node **a, stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
