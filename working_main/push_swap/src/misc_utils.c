/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:51:29 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:07:31 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	ft_count_ele(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	ft_lstsize2(stack_node *lst)
{
	int	count;

	count = 0;
	while (lst && ++count)
		lst = lst->next;
	return (count);
}

stack_node	*ft_lstlast2(stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_free(stack_node *a, stack_node *b)
{
	stack_node	*tofree;
	stack_node	*temp;

	if (a)
	{
		tofree = a;
		while (tofree)
		{
			temp = tofree;
			tofree = tofree->next;
			free(temp);
		}
	}
	if (b)
	{
		tofree = b;
		while (tofree)
		{
			temp = tofree;
			tofree = tofree->next;
			free(temp);
		}
	}
	return ;
}