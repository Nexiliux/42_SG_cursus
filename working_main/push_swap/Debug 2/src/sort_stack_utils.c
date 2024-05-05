/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:01:01 by wchow             #+#    #+#             */
/*   Updated: 2024/05/03 01:59:20 by wchow            ###   ########.fr       */
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
	printf("refresh starting.\n");
	printf("ft_lstsize: %d /2 = %d\n", ft_lstsize2(*node), ft_lstsize2(*node) / 2);
	while (head && ++i > -2)
	{
		head->index = i;
		if (head->index > ft_lstsize2(*node) / 2)
			head->above_mid = 1;
		else
			head->above_mid = 0;
		if (head->above_mid)
			head->move_price = ft_lstsize2(*node) - i;
		else
			head->move_price = i;
		printf("Index = %d Num = %d movePrice = %d\n", head->index, head->num, head->move_price);
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
	ft_printf("bignum[%d]: %d moveprice: %d\n", big->index, big->num, big->move_price);
	ft_printf("smolnum[%d]: %d moveprice: %d\n", smol->index, smol->num, smol->move_price);
	if (big->move_price <= smol->move_price)
	{
		ft_printf("acting big:\n");
		ft_printf("bignum: %d moveprice: %d\n", big->num, big->move_price);
		while (big->move_price-- > 0)
		{

			if (big->above_mid)
				rrb(b);
			else
				rb(b);
			ft_printf("bignum: %d moveprice: %d\n", big->num, big->move_price);
		}
		pa(a, b);
	}
	else
	{
		ft_printf("acting small:\n");
		ft_printf("smolnum: %d moveprice: %d\n", smol->num, smol->move_price);
		while (smol->move_price-- > 0)
		{
			if (smol->above_mid)
				rrb(b);
			else
				rb(b);
			ft_printf("smolnum: %d moveprice: %d\n", smol->num, smol->move_price);
		}
		pa(a, b);
		ra(a);
	}
}
