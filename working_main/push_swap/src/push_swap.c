/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:56 by wchow             #+#    #+#             */
/*   Updated: 2024/04/19 23:15:48 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"



int	main(int argc, char **argv)
{
	stack_node *a;
	//stack_node *b;

	a = NULL;
	//b = NULL;
	init(&a, argc, argv);
	ft_printf("Stack a struct starting to print\n");
	while (a->next)
	{
		ft_printf("Index[%d]	Num = %d\n", a->index, a->num);
		a = a->next;
	}
	//REMEMBER TO TEST THE COMMANDS
	return (0);
}
