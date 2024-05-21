/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:15:07 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 15:38:55 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_god *god, int i)
{
	god->player = mlx_xpm_file_to_image(god->mlx,
			"textures/imposter.xpm", &i, &i);
	god->crew = mlx_xpm_file_to_image(god->mlx,
			"textures/crew.xpm", &i, &i);
	god->wall = mlx_xpm_file_to_image(god->mlx,
			"textures/cheese_wall.xpm", &i, &i);
	god->tile = mlx_xpm_file_to_image(god->mlx,
			"textures/cheese.xpm", &i, &i);
	god->vent_closed = mlx_xpm_file_to_image(god->mlx,
			"textures/vent_closed.xpm", &i, &i);
	god->vent_open = mlx_xpm_file_to_image(god->mlx,
			"textures/vent_open.xpm", &i, &i);
}

void	draw_map(t_god *god, int i, int j)
{
	while (god->map[i])
	{
		j = -1;
		while (god->map[i][++j])
		{
			if (god->map[i][j] == '1')
				mlx_put_image_to_window(god->mlx, god->win, god->wall,
					j * 64, i * 64);
			else if (god->map[i][j] == '0' || god->map[i][j] == 'P')
				mlx_put_image_to_window(god->mlx, god->win, god->tile,
					j * 64, i * 64);
			else if (god->map[i][j] == 'C')
				mlx_put_image_to_window(god->mlx, god->win, god->crew,
					j * 64, i * 64);
			else if (god->map[i][j] == 'E' && god->collectibles == 0)
				mlx_put_image_to_window(god->mlx, god->win, god->vent_open,
					j * 64, i * 64);
			else if (god->map[i][j] == 'E' && god->collectibles > 0)
				mlx_put_image_to_window(god->mlx, god->win, god->vent_closed,
					j * 64, i * 64);
		}
		i++;
	}
}

int	render_next_frame(t_god *god)
{
	int	x;
	int	y;

	x = god->test_x;
	y = god->test_y;
	draw_map(god, 0, 0);
	mlx_put_image_to_window(god->mlx, god->win, god->player, x, y);
	return (0);
}
