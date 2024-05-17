/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:21 by wchow             #+#    #+#             */
/*   Updated: 2024/05/17 21:33:18 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_god *god)
{
	printf("key pressed\n");
	printf("keycode: 0x%02x\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(god->mlx, god->win);
		printf("Escape pressed. Shutting down.\n");
		exit (1);
	}
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s
		|| keycode == XK_d)
	{
		printf("wasd pressed. \n");
		if (keycode == XK_w && (god->testY - 64 >= 0))
			god->testY -= 64;
		if (keycode == XK_s && (god->testY + 64 <= god->resY - 64))
			god->testY += 64;
		if (keycode == XK_a && (god->testX - 64 >= 0))
			god->testX -= 64;
		if (keycode == XK_d && (god->testX + 64 <= god->resX - 64))
			god->testX += 64;
		printf("testX: %d\n", god->testX);
		printf("testY: %d\n", god->testY);
		//god->player_x = god->textY / 64 - 1 for playerpos;
		//god->textX / 64 - 1 for playerpos;
		//update_map(god, keycode);
		render_next_frame(god);
	}
	return (0);
}

int	exit_button(t_god *god)
{
	mlx_destroy_window(god->mlx, god->win);
	printf("Exit cross pressed. Shutting down.\n");
	exit(0);
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

/* void	update_map(t_god *god, int keycode)
{
	map[x][y] == 'C'
	if (map[x][y] == 'e' && god->collectibles <= 0)
		exit game
} */

int	render_next_frame(t_god *god)
{
	int	x = god->testX;// + 40;
	int	y = god->testY;// + 40;
	
	//draw_map(god);
	//mlx_put_image_to_window(god->mlx, god->win, god->tile, x, y);
	mlx_put_image_to_window(god->mlx, god->win, god->player, x, y);
	return (0);
}

void	load_textures(t_god *god, int i)
{
	god->player = mlx_xpm_file_to_image(god->mlx, "textures/imposter_chizz.xpm", &i, &i);
}

/* Theme: AMONG US, make the player the imposter then eat the normal crewmates, exit is vent*/

int	main(int argc, char **argv)
{
	t_god	*god;
	god = NULL;
	god = malloc(sizeof(t_god));
	god->win = NULL;
	god->mlx = NULL;
	if (argc != 2)
	{
		printf("Error.\nYou can only input 2 arguments\n");
		return (0);
	}
	god->map = parse_map(argv[1]);
	if (!check_map_validity(god))
	{
		free (god->map);
		free (god);
		return (69);
	}
	god->resX = 64 * god->cols;
	god->resY = 64 * god->rows;

	god->mlx = mlx_init();
	god->win = mlx_new_window(god->mlx, god->resX, god->resY, "Whaddup");
	load_textures(god, 24);
	
	mlx_put_image_to_window(god->mlx, god->win, god->player, 0, 0);
	mlx_hook(god->win, 17, 1L << 17, exit_button, god);
	mlx_key_hook(god->win, key_hook, god);
	mlx_loop_hook(god->mlx, render_next_frame, god);
	mlx_loop(god->mlx);
}
