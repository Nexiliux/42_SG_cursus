/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:01:01 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 16:57:29 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	set_dex_price(t_lst **node, int size)
{
	int		i;
	t_lst	*head;

	i = -1;
	head = *node;
	while (head && ++i > -2)
	{
		head->index = i;
		if (head->index > size / 2)
			head->above_mid = 1;
		else
			head->above_mid = 0;
		if (head->above_mid)
			head->move_price = size - i;
		else
			head->move_price = i;
		head = head->next;
	}
}

void	set_gmedian(t_lst **node, int gcount)
{
	t_lst	*head;
	int		i;
	int		smol;
	int		beeg;

	smol = smallest(node);
	beeg = biggest(node, smol, gcount);
	i = -1;
	head = *node;
	while (head && ++i > -2)
	{
		if (beeg % 2 && head->num > (beeg / 2) + 1)
			head->above_gmid = 1;
		else if (head->num > beeg / 2)
			head->above_gmid = 1;
		else
			head->above_gmid = 0;
		head = head->next;
	}
}

int	biggest(t_lst **node, int smol, int gcount)
{
	t_lst	*temp;
	int		biggestnum;
	int		prevbig;

	temp = *node;
	biggestnum = smol;
	prevbig = smol;
	while (--gcount > 0)
	{
		temp = *node;
		while (temp)
		{
			if (temp->num > biggestnum && biggestnum == prevbig)
				biggestnum = temp->num;
			if (temp->num > prevbig && temp->num < biggestnum)
				biggestnum = temp->num;
			temp = temp->next;
		}
		prevbig = biggestnum;
	}
	return (biggestnum);
}

void	first_action(t_lst **a, t_lst **b, int gcount)
{
	t_lst	*head;
	int		smol;
	int		beeg;

	smol = smallest(a);
	beeg = biggest(a, smol, gcount);
	while (*a && gcount)
	{
		head = *a;
		while (*a && head && gcount)
		{
			if (head->num >= smol && head->num <= beeg)
			{
				set_dex_price(a, ft_lstsize2(*a));
				move_and_push(a, b, head);
				gcount--;
				break ;
			}
			else
				head = head->next;
		}
	}
}

void	move_and_push(t_lst **a, t_lst **b, t_lst *target)
{
	while (target->move_price-- > 0)
	{
		if (target->above_mid)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	if (!target->above_gmid)
		rb(b);
}
