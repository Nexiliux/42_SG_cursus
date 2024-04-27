/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:36:20 by wchow             #+#    #+#             */
/*   Updated: 2024/04/27 17:21:32 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stack_node
{
	int	num;
	int	index;
	struct stack_node *next;
	struct stack_node *prev;
} stack_node;

//Initialisation
stack_node	*init(stack_node **a, int argc, char **argv);
int	*ft_parsing(int argc, char **argv, int *numbers);
int	ft_count_ele(char **argv);
void	ft_check_digit(char **arg);
void	ft_check_size(char **arg);
long	ft_strtol(const char *nptr);
void	ft_check_dupes(int *numbers, int argc);

//Commands
int	ft_lstsize2(stack_node *lst);
stack_node	*ft_lstlast2(stack_node *lst);

int	push(stack_node **stack_give, stack_node **stack_take);
void	pa(stack_node **a, stack_node **b);
void	pb(stack_node **a, stack_node **b);

int	swap(stack_node **stack);
void	sa(stack_node **a);
void	sb(stack_node **b);
void	ss(stack_node **a, stack_node **b);

int	rotate(stack_node **stack);
void	ra(stack_node **a);
void	rb(stack_node **b);
void	rr(stack_node **a, stack_node **b);

int	revrotate(stack_node **stack);
void	rra(stack_node **a);
void	rrb(stack_node **b);
void	rrr(stack_node **a, stack_node **b);

#endif