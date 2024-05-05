/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:20:02 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:57:43 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	smallest(t_lst **node)
{
	t_lst	*temp;
	t_lst	*smol;

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
