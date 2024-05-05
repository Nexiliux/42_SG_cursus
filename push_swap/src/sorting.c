/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:43:46 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:03:39 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

void	sort_stack(t_lst **a, t_lst **b, int gcount)
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
}

t_lst	*sort_3(t_lst *a)
{
	if (a->num > a->next->num && a->num > a->next->next->num)
	{
		ra(&a);
		if (a->num > a->next->num)
			sa(&a);
	}
	else if (a->num < a->next->num && a->num < a->next->next->num)
	{
		if (a->next->num > a->next->next->num)
		{
			sa(&a);
			ra(&a);
		}
	}
	else
	{
		if (a->num > a->next->num)
			sa(&a);
		else
			rra(&a);
	}
	return (a);
}

void	sort_5(t_lst **a, t_lst **b)
{
	t_lst	*second;
	t_lst	*smallest;
	t_lst	*head;

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

void	sort_5_push(t_lst **a, t_lst **b, t_lst *sec, t_lst *smol)
{
	static int	sec_pushed = 0;
	static int	smol_pushed = 0;

	if (ft_lstsize2(*a) == 4)
		sec_pushed = 1;
	while (ft_lstsize2(*a) > 3)
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

void	sort_5_setup(t_lst **a, t_lst *sec, t_lst *smol, int s)
{
	if ((sec->index > 2 && sec->index <= s)
		|| (smol->index > 2 && smol->index <= s))
	{
		rra(a);
		sec->index += 1;
		smol->index += 1;
	}
	else if ((sec->index <= 2 && sec->index > 0)
		|| (smol->index <= 2 && smol->index > 0))
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
