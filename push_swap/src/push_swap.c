/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:56 by wchow             #+#    #+#             */
/*   Updated: 2024/05/05 17:30:57 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"
#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	t_lst	*a;
	t_lst	*b;

	i = -1;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv = argv + 1;
	if (ft_strchr(argv[0], ' '))
	{
		split = ft_split(argv[0], ' ');
		init(&a, split);
		while (split[++i])
			free(split[i]);
		free(split);
	}
	else
		init(&a, argv);
	if (!stack_sorted(a))
		choose_sort(&a, &b);
	ft_free(a, b);
	return (0);
}
