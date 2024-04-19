/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 20:18:42 by wchow             #+#    #+#             */
/*   Updated: 2024/04/19 22:46:40 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time. */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

//need to swap values instead of pointers itself(Reasons: lower complexity and efficiency, less chance of errors and structure is not changed due to moving the nodes around)
int	swap(stack_node **stack)
{
	stack_node	*head;
	stack_node	*second;
	int	temp_num;
	int	temp_index;

	if (ft_lstsize2(*stack) == 0 || ft_lstsize2(*stack) == 1)
		return (-1);
	head = *stack; //setting first element
	second = head->next; //setting second element
	temp_num = head->num; //setting temp num to first element num
	temp_index = head->index; //setting temp index to first element index
	head->num = second->num;
	head->index = second->index;
	second->num = temp_num;
	second->index = temp_index;
	return (0);
}

void	sa(stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(stack_node **a, stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}


