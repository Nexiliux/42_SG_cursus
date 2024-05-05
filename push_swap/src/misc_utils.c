/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:51:29 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:59:33 by wchow            ###   ########.fr       */
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

int	ft_lstsize2(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst && ++count)
		lst = lst->next;
	return (count);
}

t_lst	*ft_lstlast2(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_free(t_lst *a, t_lst *b)
{
	t_lst	*tofree;
	t_lst	*temp;

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
