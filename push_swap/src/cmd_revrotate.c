/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:18 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:53:53 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	revrotate(t_lst **stack)
{
	t_lst	*head;
	t_lst	*tail;
	t_lst	*truetail;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack;
	tail = ft_lstlast2(*stack);
	truetail = *stack;
	while (truetail->next->next != NULL)
		truetail = truetail->next;
	truetail->next = NULL;
	tail->next = head;
	*stack = tail;
	return (0);
}

void	rra(t_lst **a)
{
	revrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_lst **b)
{
	revrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_lst **a, t_lst **b)
{
	revrotate(a);
	revrotate(b);
	ft_printf("rrr\n");
}
