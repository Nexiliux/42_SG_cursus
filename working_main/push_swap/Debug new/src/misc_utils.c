/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:51:29 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 17:48:51 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	ft_count_ele(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if ((ft_strncmp(argv[0], "./push_swap", 11)) != 0) //if ./push_swap exists, add 1 to argc. Basically it's just because of ft_split essentially removing program name
		i++;
	return (i - 1); //return all inputs including ./push_swap
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