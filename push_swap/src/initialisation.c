/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:47:59 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:21:01 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

t_lst	*init_stack(int *numbers, int size)
{
	t_lst	*head;
	t_lst	*new_node;

	head = NULL;
	while (size--)
	{
		new_node = (t_lst *)malloc(sizeof(t_lst));
		if (new_node == NULL)
			return (0);
		new_node->num = numbers[size];
		new_node->index = size;
		new_node->next = head;
		head = new_node;
	}
	return (head);
}

t_lst	*init(t_lst **a, char **split)
{
	int	*numbers;
	int	elecount;

	elecount = ft_count_ele(split);
	numbers = malloc(elecount * sizeof(int));
	if (!numbers)
		return (0);
	numbers = ft_parsing(elecount, split, numbers);
	if (!numbers)
	{
		ft_free(*a, NULL);
		ft_error(numbers, NULL, NULL);
	}
	*a = init_stack(numbers, elecount);
	free(numbers);
	return (*a);
}
