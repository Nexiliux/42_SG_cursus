/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:01:01 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 14:32:45 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	set_dex_price(stack_node **node, int size)
{
	int	i;//To use as index counter
	stack_node	*head;

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

void	set_gmedian(stack_node **node, int gcount)
{
	//This is to set the boolean for whether the number in the current group is above or below
	//the median. (whether to rb or not)
	//use ->num to determine median
	//if ->num is odd then add 1 to the / 2 result
	int	i;
	stack_node	*head;
	int	smol;
	int	beeg;
	
	smol = smallest(node);
	beeg = biggest(node, smol, gcount);
	i = -1;
	head = *node;
	while (head && ++i > -2)
	{
		if (beeg % 2 && head->num > (beeg / 2) + 1) //if odd
			head->above_gmid = 1;
		else if (head->num > beeg / 2)
			head->above_gmid = 1;
		else
			head->above_gmid = 0;
		head = head->next;
	}
}

int	biggest(stack_node **node, int smol, int gcount)
{
	//the goal is to find out the biggest in the group
	//use gcount to count from the smallest up 20 times
	//To find the biggest number, use a while loop, start with the smallest in stack, then find the next smallest
	//save the next smallest as the previous number, then restart the loop with previous number as smallest
	//do this gcount # of times.
	stack_node	*temp;
	int	biggestnum;
	int	prevbig;

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
			if (temp->num > prevbig && temp->num < biggestnum) //finding smallest + 1
				biggestnum = temp->num; //setting next smallest
			temp = temp->next;
		}
		prevbig = biggestnum;
	}
	return (biggestnum);
}


void	first_action(stack_node **a, stack_node **b, int gcount)
{
	stack_node	*head;
	int	smol;
	int	beeg;

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

void	move_and_push(stack_node **a, stack_node **b, stack_node *target)
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
