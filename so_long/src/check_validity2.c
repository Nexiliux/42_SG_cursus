/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:17:23 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 20:38:17 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_god *god)
{
	int	row;
	int	col;

	row = -1;
	while (god->map[++row])
	{
		col = -1;
		while (god->map[row][++col])
		{
			if (god->map[row][col] == 'P')
			{
				god->player_x = col;
				god->player_y = row;
			}
		}
	}
}

void	map_size(t_god *god)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (god->map[rows])
		rows++;
	if (rows > 0)
		while (god->map[0][cols])
			cols++;
	god->rows = rows;
	god->cols = cols;
}

int	floodfill(char **map, int x, int y, t_god *god)
{
	int	count;
	int	rows;
	int	cols;

	count = 0;
	rows = god->rows;
	cols = god->cols;
	if (x < 0 || x >= rows || y < 0 || y >= cols || (map[x][y] != 'C'
		&& map[x][y] != 'P' && map[x][y] != '0' && map[x][y] != 'E'))
		return (0);
	if (map[x][y] == 'C')
		count = 1;
	if (map[x][y] == 'E')
		god->exit = 1;
	map[x][y] = 'V';
	count += floodfill(map, x + 1, y, god);
	count += floodfill(map, x - 1, y, god);
	count += floodfill(map, x, y + 1, god);
	count += floodfill(map, x, y - 1, god);
	return (count);
}

int	check_collect_validity(t_god *god)
{
	int		i;
	int		reachable;
	char	**copy;

	copy = malloc(sizeof(char *) * (god->rows + 1));
	i = -1;
	while (++i < god->rows)
		copy[i] = ft_strdup(god->map[i]);
	copy[i] = NULL;
	i = 0;
	reachable = floodfill(copy, god->player_y, god->player_x, god);
	while (i < god->rows)
	{
		free (copy[i]);
		i++;
	}
	free(copy);
	return (reachable == god->collectibles);
}
