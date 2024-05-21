/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:15 by wchow             #+#    #+#             */
/*   Updated: 2024/05/19 19:42:39 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_button(t_god *god)
{
	printf("Exit cross pressed. Shutting down.\n");
	exit_game(god, god->rows);
	return (0);
}

void	exit_game(t_god *god, int maprows)
{
	if (god->win)
		mlx_destroy_window(god->mlx, god->win);
	if (god->mlx)
		free(god->mlx);
	while (--maprows >= 0)
		free(god->map[maprows]);
	free(god->map);
	free(god->player);
	free(god->crew);
	free(god->wall);
	free(god->tile);
	free(god->vent_closed);
	free(god->vent_open);
	free(god);
	exit(1);
}

void	god_init(t_god *god)
{
	god->mlx = NULL;
	god->win = NULL;
	god->addr = NULL;
	god->collectibles = 0;
	god->player_x = 0;
	god->player_y = 0;
	god->rows = 0;
	god->cols = 0;
	god->testX = 0;
	god->testY = 0;
	god->resX = 0;
	god->resY = 0;
	god->player = NULL;
	god->crew = NULL;
	god->wall = NULL;
	god->tile = NULL;
	god->vent_closed = NULL;
	god->vent_open = NULL;
}
