/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:18 by wchow             #+#    #+#             */
/*   Updated: 2024/04/19 22:47:03 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	revrotate(stack_node **stack)
{
	stack_node	*head;
	stack_node	*tail;
	stack_node	*truetail;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack; //setting head
	tail = ft_lstlast2(*stack); //setting tail
	truetail = *stack; //prepping to move truetail to the 2nd last
	while (truetail->next->next != NULL) //moving truetail to 2nd last element
		truetail = truetail->next;
	truetail->next = NULL; //closing the tail
	tail->next = head; //moving head to the 2nd element
	*stack = tail; //updating stack pointer to point to tail, the current head element
	return (0);
}

void	rra(stack_node **a)
{
	revrotate(a);
	ft_printf("rra\n");
}

void	rrb(stack_node **b)
{
	revrotate(b);
	ft_printf("rrb\n");
}

void	rrr(stack_node **a, stack_node **b)
{
	revrotate(a);
	revrotate(b);
	ft_printf("rrr\n");
}