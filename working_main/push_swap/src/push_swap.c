/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:56 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 17:57:06 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"



int	main(int argc, char **argv)
{
	stack_node *a;
	stack_node *b;
	stack_node *testA;
	stack_node *testB;

	a = NULL;
	b = NULL;
	init(&a, argc, argv);
	testA = a;
	testB = b;
	ft_printf("Starting struct values:\n");
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("-----------------------------------------\nAfter pb:\n");
	pb(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("-----------------------------------------\nAfter pa:\n");
	pa(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("Swap test beginning.\n");
	ft_printf("-----------------------------------------\nAfter 3pb:\n");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("-----------------------------------------\nAfter 3pb then ss:\n");
	ss(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("SWAP TEST ENDED\n");
	ft_printf("Rotate test beginning.\n");
	ft_printf("-----------------------------------------\nAfter rr:\n");
	rr(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("ROTATE TEST ENDED\n");
	ft_printf("Reverse Rotate test beginning.\n");
	ft_printf("-----------------------------------------\nAfter rrr:\n");
	rrr(&a, &b);
	testA = a;
	testB = b; 
	ft_printf("Stack A values:\n");
	while (testA)
	{

		ft_printf("Index[%d]	Num = %d\n", testA->index, testA->num);
		testA = testA->next;
	}
	ft_printf("Stack B values:\n");
	while (testB)
	{

		ft_printf("Index[%d]	Num = %d\n", testB->index, testB->num);
		testB = testB->next;
	}
	ft_printf("REVERSE ROTATE TEST ENDED\n");
	//ALL TESTS WORK with 'make re && ./push_swap 1 2 3 4 5 6 && ./push_swap "1 2 3 4 5 6"'
	return (0);
}
