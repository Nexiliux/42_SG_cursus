/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:43:46 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 14:27:22 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

/* The idea is to group numbers based on the smallest value first, 
the number of elements in a group is hardcoded.
The elements pushed will not be semi-sorted, in the sense where when a number from that group is pushed, 
it is checked against the median in the group. Stack B is rotated based on whether the element is 
higher or lower than the median. This further groups the numbers. */
//Find smallest first, then use smallest->num to count grouping # to find the biggest number in the group
//move up and push #groupcount# number of times anything below the biggest in the group
//whenever a number is pushed, the median boolean (which is set beforehand) is used to determine whether
//stack B is rotated after pushing. This further sorts each group by above or below median.


void	sort_stack(stack_node **a, stack_node **b, int gcount)
{

	while (*a)
	{
		set_gmedian(a, gcount);
		first_action(a, b, gcount);
	}
	while (*b)
	{
		second_action(a, b);
	}
	/* while (!stack_sorted(*a))
	{
		smol = smallest(a);
		if (smol->above_mid)
			rra(a);
		else
			ra(a);
	} */
}
		

stack_node	*sort_3(stack_node *a)
{
	if (a->num > a->next->num && a->num > a->next->next->num) //biggest on top
	{
		ra(&a);
		if (a->num > a->next->num) //swap if smallest not on top
			sa(&a);
	}
	else if (a->num < a->next->num && a->num < a->next->next->num) //smallest on top
	{
		if (a->next->num > a->next->next->num)
		{
			sa(&a); //order is confirm 132, so just swap to 312 first
			ra(&a); //push up so it becomes 123;
		}
	}
	else //order is either 213 or 231
	{
		if (a->num > a->next->num) //if it's 213
			sa(&a);
		else //if it's 231
			rra(&a);
	}
	return (a);
}
void	sort_5(stack_node **a, stack_node **b)
{
	stack_node	*second;
	stack_node	*smallest;	//3 4 1 5 2 | 1 4 3 5 2
	stack_node	*head;

	second = *a;
	smallest = *a;
	head = *a;
	while (head)
	{
		if (!smallest || head->num < smallest->num)
		{
			second = smallest;
			smallest = head;
		}
		else if (!second || (head->num < second->num && head != smallest))
			second = head;
		head = head->next;
	}
	sort_5_push(a, b, second, smallest);
	*a = sort_3(*a);
	if (stack_sorted(*b))
		sb(b);
	while (ft_lstsize2(*b) > 0)
		pa(a, b);
}

void	sort_5_push(stack_node **a, stack_node **b, stack_node *sec, stack_node *smol)
{
	static int	sec_pushed = 0;
	static int	smol_pushed = 0;

	if (ft_lstsize2(*a) == 4)
		sec_pushed = 1;
	while (ft_lstsize2(*a) > 3) // 0 1 2 3 4 | 1 2 3 4 
	{
		if ((sec->index <= 0 || sec->index > 4) && !sec_pushed) 
		{
			pb(a, b);
			smol->index -= 1;
			sec->index = -10;
			sec_pushed = 1;
		}
		else if ((smol->index <= 0 || smol->index > 4) && !smol_pushed)
		{
			pb(a, b);
			sec->index -= 1;
			smol->index = -10;
			smol_pushed = 1;
		}
		else 
			sort_5_setup(a, sec, smol, ft_lstsize2(*a) - 1);
	}
}

void	sort_5_setup(stack_node **a, stack_node *sec, stack_node *smol, int s)
{
	if ((sec->index > 2 && sec->index <= s) || (smol->index > 2 && smol->index <= s))
	{
		rra(a);
		sec->index += 1;
		smol->index += 1;
	}
	else if ((sec->index <= 2 && sec->index > 0) || (smol->index <= 2 && smol->index > 0))
	{
		ra(a);
		sec->index -= 1;
		smol->index -= 1;
	}
	if (sec->index > s)
		sec->index = 0;
	if (sec->index < 0 && sec->index < -2)
		sec->index = s;
	if (smol->index > s)
		smol->index = 0;
	if (smol->index < 0 && smol->index < -2)
		smol->index = s;
}
