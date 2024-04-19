/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:59 by wchow             #+#    #+#             */
/*   Updated: 2024/04/13 22:03:39 by wchow            ###   ########.fr       */
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

	i = 0;
	head = NULL;
	tail = NULL;
	while (i < size)
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
		i++; // Move to the next element in the array
	}
	return (head); // Return the head of the list
}

stack_node	*init_stack(int *numbers, int size)
{
	stack_node	*head;
	stack_node	*tail;
	int	i;

	i = 0;
	head = NULL;
	tail = NULL;
	while (i < size)
	{
		stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
		if (new_node == NULL)
			return (0);
		new_node->num = numbers[i];
		new_node->index = i;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		i++; // Move to the next element in the array
	}
	return (head); // Return the head of the list
}

void	*init(stack_node *a, int argc, char **argv)
{
	int	*numbers;
	int	i = 0;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	
	argc = ft_count_ele(argv);
	numbers = malloc((argc - 1) * sizeof(int));
	numbers = ft_parsing(argc, argv, numbers);

	while (i < argc - 1)
	{
		ft_printf("Numbers[%d]: %d\n", i, numbers[i]);
		i++;
	}

	a = NULL;
	a = init_stack(numbers, argc);
}