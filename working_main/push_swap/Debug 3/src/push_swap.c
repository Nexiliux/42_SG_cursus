/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:56 by wchow             #+#    #+#             */
/*   Updated: 2024/05/04 17:30:20 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

/* char **split;

split = NULL;
if (argc == 1)
 return (0);
argv = argv + 1;
if (ft_strchr(argv, ' '))
{
 split = ft_split(argv, ' ');
 init(split);
}
else
 init(argv);
.
.
.
if (split)
 free_split(split);
 */
int	main(int argc, char **argv)
{
	char	**split;
	stack_node *a;
	stack_node *b;

	split = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv = argv + 1;
	if (ft_strchr(argv[0], ' '))
	{
		split = ft_split(argv[0], ' ');
		init(&a, split);
	}
	else
		init(&a, argv);
	if (!stack_sorted(a))
		choose_sort(&a , &b);/*  */
	if (split)
		free(split);

	stack_node *testA;
	stack_node *testB;
	ft_printf("Stack is sorted!\n");
	ft_printf("Starting struct values:\n");
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
	return (0);
}
	//TESTS FOR COMMANDS:
/*	
	stack_node *testA;
	stack_node *testB;

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
	//ALL TESTS WORK with 'make re && ./push_swap 1 2 3 4 5 6 && ./push_swap "1 2 3 4 5 6"' */
