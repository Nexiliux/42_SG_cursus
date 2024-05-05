/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:35 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:54:55 by wchow            ###   ########.fr       */
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

int	rotate(t_lst **stack)
{
	t_lst	*head;
	t_lst	*tail;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack;
	tail = ft_lstlast2(*stack);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}

void	ra(t_lst **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_lst **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
