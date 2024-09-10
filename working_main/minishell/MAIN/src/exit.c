/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 04:51:00 by wchow             #+#    #+#             */
/*   Updated: 2024/09/10 16:54:11 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(void)
{
	
}

void	freeData(t_data *data)
{
	int	i;

	i = -1;
	while (++i >= -1 && data->env[i])
		free (data->env[i]);
	free(data->env);
	free(data->path);
	free(data);
}