/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:36:20 by wchow             #+#    #+#             */
/*   Updated: 2024/04/13 21:04:44 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//Initialisation
void	*init(stack_node *a, int argc, char **argv);
int	*ft_parsing(int argc, char **argv, int *numbers);
int	ft_count_ele(char **argv);
void	ft_check_digit(char **arg);
void	ft_check_size(char **arg);
long	ft_strtol(const char *nptr);
void	ft_check_dupes(int *numbers, int argc);


typedef struct t_stack_node
{
	int	num;
	int	index;
	struct stack_node *next;
	struct stack_node *prev;
} stack_node;

#endif