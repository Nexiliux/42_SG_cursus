/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:42 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:55:44 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	swap(t_lst **stack)
{
	t_lst	*head;
	t_lst	*second;
	int		temp_num;
	int		temp_index;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack;
	second = head->next;
	temp_num = head->num;
	temp_index = head->index;
	head->num = second->num;
	head->index = second->index;
	second->num = temp_num;
	second->index = temp_index;
	return (0);
}

void	sa(t_lst **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_lst **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_lst **a, t_lst **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
