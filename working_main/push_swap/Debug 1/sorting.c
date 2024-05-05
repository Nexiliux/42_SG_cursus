/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:43:46 by wchow             #+#    #+#             */
/*   Updated: 2024/04/29 02:06:05 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

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
	/* while (head)
	{
		if (smallest->num > head->num)
			smallest = head;
		if (second == NULL || (head->num < second->num && head->num > smallest->num))
			second = head;
		head = head->next;
	} */
	while (head != NULL) {
    if (smallest == NULL || head->num < smallest->num) {
        second = smallest;  // Update 'second' to the previous 'smallest' node
        smallest = head;    // Update 'smallest' to the new smallest node
    } else if (second == NULL || (head->num < second->num && head != smallest)) {
        second = head;      // Update 'second' to the new second smallest node
    }
    head = head->next;      // Move to the next node
}

	if (ft_lstsize2(*a) == 4)
		second = smallest;

	ft_printf("Second:[%d]	Smallest:[%d]\n", second->num, smallest->num);

	sort_5_push(a, b, second, smallest);

	ft_printf("after sort_5_push values:\n");
	stack_node *testA;
	stack_node *testB;
	testA = *a;
	testB = *b;
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("current size of A is: %d\n", ft_lstsize2(*a));
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("current size of B is: %d\n", ft_lstsize2(*b));

	*a = sort_3(*a);
	if (stack_sorted(*b))
		sb(b);

	ft_printf("after sort3 values:\n");
	testA = *a;
	testB = *b;
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("current size of A is: %d\n", ft_lstsize2(*a));
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("current size of B is: %d\n", ft_lstsize2(*b));
	
	while (ft_lstsize2(*b) > 0)
		pa(a, b);
}

/* void	sort_5_push(stack_node **a, stack_node **b, stack_node *sec, stack_node *smol)
{
	while (ft_lstsize2(*a) > 3) // 0 1 2 3 4 | 1 2 3 4 
	{
		ft_printf("Second index:[%d]	Smallest index:[%d]\n", sec->index, smol->index);
		if (sec->index <= 0 || sec->index > 4)
			pb(a, b);
		if (smol->index <= 0 || smol->index > 4)
			pb(a, b);
		if ((sec->index > 2 && sec->index < 5) || (smol->index > 2 && smol->index < 5))
		{
			ft_printf("1st while entered\n");
			rra(a);
			if (sec->index > 2)
				sec->index += 1;
			if (smol->index > 2)
				smol->index += 1;
		}
		else if ((sec->index <= 2 && sec->index > 0) || (smol->index <= 2 && smol->index > 0))
		{
			ft_printf("2nd while entered\n");
			ra(a);
			if (sec->index <= 2)
				sec->index -= 1;
			if (smol->index <= 2)
				smol->index -= 1;
		}
		ft_printf("ran till the end\n");
	}
} */

void	sort_5_push(stack_node **a, stack_node **b, stack_node *sec, stack_node *smol)
{
	static int	sec_pushed = 0;
	static int	smol_pushed = 0;
	int	max_index;

	while (ft_lstsize2(*a) > 3) // 0 1 2 3 4 | 1 2 3 4 
	{
		max_index = ft_lstsize2(*a) - 1;
		ft_printf("----Second index:[%d]	Smallest index:[%d]\n", sec->index, smol->index);
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
			sort_5_setup(a, sec, smol, max_index);
		ft_printf("current size of A is: %d\n", ft_lstsize2(*a));
		ft_printf("++++Second index:[%d]	Smallest index:[%d]\n", sec->index, smol->index);
	stack_node *testA;
	stack_node *testB;
	testA = *a;
	testB = *b;
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("current size of A is: %d\n", ft_lstsize2(*a));
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
		ft_printf("ran till the end\n");
	}
}

void	sort_5_setup(stack_node **a, stack_node *sec, stack_node *smol, int s)
{
	ft_printf("S is: %d\n", s);
	if ((sec->index > 2 && sec->index <= s) || (smol->index > 2 && smol->index <= s))
	{
		ft_printf("1st while entered\n");
		rra(a);
		sec->index += 1;
		smol->index += 1;
	}
	else if ((sec->index <= 2 && sec->index > 0) || (smol->index <= 2 && smol->index > 0))
	{
		ft_printf("2nd while entered\n");
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
	ft_printf("sec->num is: %d\n", sec->num);
}
