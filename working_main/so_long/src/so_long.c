/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:21 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 15:12:09 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_god *god)
{
	if (keycode == XK_Escape)
	{
		printf("Escape pressed. Shutting down.\n");
		exit_game(god, god->rows);
	}
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d)
	{
		if (keycode == XK_w && (god->testY - 64 >= 0))
			god->testY -= 64;
		if (keycode == XK_s && (god->testY + 64 <= god->resY - 64))
			god->testY += 64;
		if (keycode == XK_a && (god->testX - 64 >= 0))
			god->testX -= 64;
		if (keycode == XK_d && (god->testX + 64 <= god->resX - 64))
			god->testX += 64;
		//printf("testX: %d\n", god->testX);
		//printf("testY: %d\n", god->testY);
		check_collision(god, god->testX / 64, god->testY / 64, keycode);
		//printf("After collision check X: %d\n", god->testX);
		//printf("After collision check Y: %d\n", god->testY);
		update_map(god, god->testX / 64, god->testY / 64);
		render_next_frame(god);
	}
	return (0);
}



char	**parse_map(char *arg)
{
	//check validity of map then push the map into 2D array.
	//Proceed to process graphical management and textures based on the map
	int	fd;
	char	*line;
	char	**result;
	int	i;

	i = 0;
	result = malloc(sizeof(char *) * 1024);
	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		result[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		ft_strlcpy(result[i], line, ft_strlen(line) + 1);
		free (line);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	main(int argc, char **argv)
{
	t_god	*god;

	god = malloc(sizeof(t_god));
	if (argc != 2)
	{
		printf("Error.\nYou can only input 2 arguments\n");
		return (0);
	}
	god_init(god);
	god->map = parse_map(argv[1]);
	if (!check_map_validity(god))
		exit_game(god, god->rows);
	god->resX = 64 * god->cols;
	god->resY = 64 * god->rows;
	god->testX = 64 * god->player_x;
	god->testY = 64 * god->player_y;
	god->mlx = mlx_init();
	god->win = mlx_new_window(god->mlx, god->resX, god->resY, "yo");
	load_textures(god, 64);
	render_next_frame(god);
	mlx_hook(god->win, 17, 1L << 17, exit_button, god);
	mlx_key_hook(god->win, key_hook, god);
	mlx_loop(god->mlx);
}
