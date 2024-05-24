/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:36:20 by wchow             #+#    #+#             */
/*   Updated: 2024/05/24 14:38:48 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lst
{
	int				num;
	int				index;
	int				above_mid;
	int				above_gmid;
	int				move_price;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

//Initialisation
t_lst	*init(t_lst **a, char **split);
int		*ft_parsing(int elecount, char **split, int *numbers);
int		ft_count_ele(char **argv);
int		ft_check_digit(char **arg);
int		ft_check_size(char **arg);
long	ft_strtol(const char *nptr);
int		ft_check_dupes(int *numbers, int argc);

//Commands
int		ft_lstsize2(t_lst *lst);
t_lst	*ft_lstlast2(t_lst *lst);

int		push(t_lst **stack_give, t_lst **stack_take);
void	pa(t_lst **a, t_lst **b);
void	pb(t_lst **a, t_lst **b);

int		swap(t_lst **stack);
void	sa(t_lst **a);
void	sb(t_lst **b);
void	ss(t_lst **a, t_lst **b);

int		rotate(t_lst **stack);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);

int		revrotate(t_lst **stack);
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);

//Sorting
void	sort_stack(t_lst **a, t_lst **b, int gcount);
int		biggest(t_lst **node, int smol, int gcount);
int		smallest(t_lst **node);
void	set_gmedian(t_lst **node, int gcount);
void	set_dex_price(t_lst **node, int size);
void	move_and_push(t_lst **a, t_lst **b, t_lst *target);
void	first_action(t_lst **a, t_lst **b, int gcount);

t_lst	*big_to_push(t_lst **node);
void	second_action(t_lst **a, t_lst **b);

void	sort_5(t_lst **a, t_lst **b);
t_lst	*sort_3(t_lst *a);

//Utilities
int		stack_sorted(t_lst *a);
void	choose_sort(t_lst **a, t_lst **b);
void	ft_free(t_lst *a, t_lst *b);

#endif
