/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:59 by wchow             #+#    #+#             */
/*   Updated: 2024/05/03 00:36:15 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

stack_node	*init_stack(int *numbers, int size)
{
	stack_node	*head;
	stack_node	*tail;
	int	i;

	i = -1;
	head = NULL;
	tail = NULL;
	while (++i < size)
	{
		stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
		if (new_node == NULL)
			return (0);
		new_node->num = numbers[i];
		new_node->index = i;
		new_node->next = NULL;
		if (head == NULL)
		{
			// If it's the first node, set it as both head and tail
			head = new_node;
			tail = new_node;
		}
		else
		{
			// Append the new node to the end of the list
			tail->next = new_node;
			tail = new_node;
		}
	}
	return (head); // Return the head of the list
}

stack_node	*init(stack_node **a, char **split)
{
	int	*numbers;
	int	elecount;
	int	i = 0;

	/* while (argv[i])
	{
		ft_printf("argv[%d] is: %d ", i, argv[i][0]);
		i++;
	}
	ft_printf("\ni is: %d\n", i);
	i = 0; */

	elecount = ft_count_ele(split);
	//ft_printf("\nargc after ft_count_ele is: %d\n", argc);
	numbers = malloc(elecount * sizeof(int));
	numbers = ft_parsing(elecount, split, numbers);

	ft_printf("Numbers array starting to print:\n");
	while (i < elecount)
	{
		ft_printf("Numbers[%d]: %d\n", i, numbers[i]);
		i++;
	}

	*a = init_stack(numbers, elecount);
	free(numbers);
	return (*a);
}
