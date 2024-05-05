/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:20:02 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 14:20:21 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	smallest(stack_node **node)
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
	return (smol->num);
}