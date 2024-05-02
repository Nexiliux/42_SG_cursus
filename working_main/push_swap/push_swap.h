/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:36:20 by wchow             #+#    #+#             */
/*   Updated: 2024/05/03 00:52:40 by wchow            ###   ########.fr       */
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
	int	above_mid; //whether the index # is more than median
	int	move_price;
	struct stack_node *next;
	struct stack_node *prev;
} stack_node;

//Initialisation
stack_node	*init(stack_node **a, char **split);
int	*ft_parsing(int elecount, char **split, int *numbers);
int	ft_count_ele(char **argv);
void	ft_check_digit(char **arg);
void	ft_check_size(char **arg);
long	ft_strtol(const char *nptr);
void	ft_check_dupes(int *numbers, int argc);

//Commands
int	ft_lstsize2(stack_node *lst);
stack_node	*ft_lstlast2(stack_node *lst);

int	push(stack_node **stack_give, stack_node **stack_take);
void	pa(stack_node **a, stack_node **b); //b to a
void	pb(stack_node **a, stack_node **b); //a to b

int	swap(stack_node **stack); //swap first two elements
void	sa(stack_node **a);
void	sb(stack_node **b);
void	ss(stack_node **a, stack_node **b);

int	rotate(stack_node **stack); //shift up all elements by 1. The first element becomes last.
void	ra(stack_node **a);
void	rb(stack_node **b);
void	rr(stack_node **a, stack_node **b);

int	revrotate(stack_node **stack); //shift down all elements by 1. The last element becomes first.
void	rra(stack_node **a);
void	rrb(stack_node **b);
void	rrr(stack_node **a, stack_node **b);

//Sorting
void	sort_stack(stack_node **a, stack_node **b);
void	refresh(stack_node **node);
stack_node	*biggest(stack_node **node);
stack_node	*smallest(stack_node **node);
void	action(stack_node *big, stack_node *smol, stack_node **a, stack_node **b);

void	sort_5(stack_node **a, stack_node **b);
void	sort_5_push(stack_node **a, stack_node **b, stack_node *sec, stack_node *smol);
void	sort_5_setup(stack_node **a, stack_node *sec, stack_node *smol, int s);

stack_node	*sort_3(stack_node *a);

//Utilities
int	stack_sorted(stack_node *a);

#endif
