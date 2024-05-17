/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:46:08 by wchow             #+#    #+#             */
/*   Updated: 2024/05/17 21:30:05 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_structure(t_god *god)
{
    int	i;
	size_t	count;

	i = 0;
	while (god->map[i])
	{
		count = ft_strlen(god->map[i]);
		if (god->map[i + 1] && count != ft_strlen(god->map[i + 1])
			&& god->map[i + 1][0] == '\n')
		{
			printf("i: %d\n", i);
			printf("Error.\nInvalid map structure. Make sure it's a rectangle\n");
			return (0);
		}
        	i++;
	}
	return (1);
}

int	check_amounts(t_god *god, int p, int e, int c)
{
	int	i;
	int	j;

	i = -1;
	while(god->map[++i])
	{
		j = -1;
		while(god->map[i][++j])
		{
			if (god->map[i][j] == 'P')
				p++;
			if (god->map[i][j] == 'E')
				e++;
			if (god->map[i][j] == 'C')
			{
				c++;
				god->collectibles++;
			}
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int	check_elements(t_god *god)
{
	int	i;
	int	j;

	i = -1;
	while(god->map[++i])
	{
		j = 0;
		while(god->map[i][j] && god->map[i][j] != '\n')
		{
			if (god->map[i][j] == 'P' || god->map[i][j] == 'E' || god->map[i][j] == 'C'
				|| god->map[i][j] == '1' || god->map[i][j] == '0')
				j++;
			else
			{
				printf("Error.\nUse only 1, 0, P, C and E.\n");
				return (0);
			}
		}
	}
	return (1);
}

int	check_walls(t_god *god, int i, int j)
{
	int	row_len;

	while (god->map[0][j] && god->map[i][j] != '\n')
	{
		if (god->map[0][j] != '1')
			return (0);
		j++;
	}
	row_len = j - 1;
	while(god->map[i + 1])
	{
		if (god->map[i][0] != '1' || god->map[i][row_len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (god->map[i][j] && god->map[i][j] != '\n')
	{
		if (god->map[i][j] && god->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
void	find_player(t_god *god)
{
	int	row;
	int	col;

	row = -1;
	while(god->map[++row])
	{
		col = -1;
		while(god->map[row][++col])
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
	//if E is untraveseable then adjust floodfill logic accordingly
	//If 
	int	count;
	int	rows;
	int	cols;

	count = 0;
	rows = god->rows;
	cols = god->cols;
	if (x < 0 || x >= rows || y < 0 || y >= cols || (map[x][y] != 'C'
		&& map[x][y] != 'P' && map[x][y] != '0'))
        return 0;
	if (x < 0 || x >= rows || y < 0 || y >= cols || (map[x][y] != 'C'
		&& map[x][y] != 'P' && map[x][y] != '0'))
		return 0;
	if (map[x][y] == 'C')
		count = 1;
	map[x][y] = 'V';
	count += floodfill(map, x + 1, y, god);
	count += floodfill(map, x - 1, y, god);
	count += floodfill(map, x, y + 1, god);
	count += floodfill(map, x, y - 1, god);
	return (count);
}


int	check_collect_validity(t_god *god)
{
	char	**copy;
	int	i;
	int	reachable;

	map_size(god);
	find_player(god);
	copy = malloc(sizeof(char *) * (god->rows + 1));
	i = -1;
	while (++i < god->rows)
		copy[i] = ft_strdup(god->map[i]);
	copy[i] = NULL;

	/* i = 0;
	while (i < god->rows)
	{
		printf("%s\n", copy[i]);
		i++;
	}
	printf("player X: %d\n", god->player_x);
	printf("player Y: %d\n", god->player_y); */

	i = 0;
	reachable = floodfill(copy, god->player_y, god->player_x, god);
	ft_printf("Collectibles in map: %d\n", god->collectibles);
	ft_printf("Collectibles reachable: %d\n", reachable);
	while (i < god->rows)
	{
		free (copy[i]);
		i++;
	}
	return (reachable == god->collectibles);
}

int	check_map_validity(t_god *god)
{
	if (!check_structure(god))
		return (0);
	if (!check_amounts(god, 0, 0, 0))
	{
		printf("Error.\nInvalid amounts of player/element/collectibles.\n");
		return (0);
	}
	if (!check_elements(god))
		return (0);
	if (!check_walls(god, 1, 0))
	{
		printf("Error.\nMake sure surrounding walls are 1s.\n");
		return (0);
	}
	if (!check_collect_validity(god))
	{
		printf("Error\nMake sure all collectibles can be reached.\n");
		return (0);
	}
	return (1);
}
