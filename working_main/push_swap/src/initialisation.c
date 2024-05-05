/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:59 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 15:25:53 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

stack_node	*init_stack(int *numbers, int size)
{
	stack_node	*head;

	head = NULL;
	while (size--)
	{
		stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
		if (new_node == NULL)
			return (0);
		new_node->num = numbers[size];
		new_node->index = size;
		new_node->next = head;
		head = new_node;
	}
	return (head); // Return the head of the list
}

stack_node	*init(stack_node **a, char **split)
{
	int	*numbers;
	int	elecount;
	elecount = ft_count_ele(split);
	numbers = malloc(elecount * sizeof(int));
		if (!numbers)
			return (0);
	numbers = ft_parsing(elecount, split, numbers);
	*a = init_stack(numbers, elecount);
	free(numbers);
	return (*a);
}
