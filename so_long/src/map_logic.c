/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:14:14 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 20:55:57 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_map(t_god *god, int px, int py)
{
	if (god->map[py][px] == 'C')
	{
		god->collectibles--;
		god->map[py][px] = '0';
	}
	if (god->map[py][px] == 'E' && god->collectibles <= 0)
		exit_game(god, god->rows + 1);
}

void	check_collision(t_god *god, int px, int py, int keycode)
{
	if (god->map[py][px] == '1')
	{
		if (keycode == XK_w)
			god->test_y += 64;
		if (keycode == XK_s)
			god->test_y -= 64;
		if (keycode == XK_a)
			god->test_x += 64;
		if (keycode == XK_d)
			god->test_x -= 64;
	}
	else
	{
		god->moves++;
		ft_printf("Moves: %d\n", god->moves);
	}
}
