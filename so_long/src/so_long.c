/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:21 by wchow             #+#    #+#             */
/*   Updated: 2024/05/16 19:06:20 by wchow            ###   ########.fr       */
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
		if (keycode == XK_w && (god->testY - 40 >= 0))
			god->testY -= 40;
		if (keycode == XK_s && (god->testY + 40 <= 680))
			god->testY += 40;
		if (keycode == XK_a && (god->testX - 40 >= 0))
			god->testX -= 40;
		if (keycode == XK_d && (god->testX + 40 <= 1240))
			god->testX += 40;
		printf("testX: %d\n", god->testX);
		printf("testY: %d\n", god->testY);
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

/*void	ft_mlx_pixel_put(t_god *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

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

int	render_next_frame(t_god *god)
{
	//mlx_destroy_image(god->mlx,god->img);
	//god->img = mlx_new_image(god->mlx, 1280, 720);
	//god->addr = mlx_get_data_addr(god->img, &god->bits_per_pixel, &god->line_length, &god->endian);
	int	x = god->testX;// + 40;
	int	y = god->testY;// + 40;
	/*int	solidx = 40;
	int	solidy = 40;
	while (solidy != 0)
	{
		solidx = 40;
		while (solidx != 0)
		{
			ft_mlx_pixel_put(god, solidx, solidy, 0x00FFFFFF);
			solidx--;
		}
		solidy--;
	}*/
	/* while (y != god->testY)
	{
		x = god->testX + 40;
		while (x != god->testX)
		{
			ft_mlx_pixel_put(god, x, y, 0x0000FFFF);
			x--;
		}
		y--;
	} */
	//ft_printf("In render next frame: x: %d y: %d\n", x, y);
	mlx_put_image_to_window(god->mlx, god->win, god->player, x, y);
	return (0);
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

	god->mlx = mlx_init();
	god->win = mlx_new_window(god->mlx, 1280, 720, "Whaddup");
	//god->img = mlx_new_image(god->mlx, 1280, 720);
	//god->addr = mlx_get_data_addr(god->img, &god->bits_per_pixel, &god->line_length, &god->endian);

	int	x = god->testX + 24;
	//int	y = god->testY + 30;
	
 	/*while (y != god->testY)
	{
		x = god->testX + 30;
		while (x != god->testX)
		{
			ft_mlx_pixel_put(god, x, y, 0x0000FFFF);
			x--;
		}
		y--;
	}*/
	/*if (god->img == NULL)
		return (69);
	if (god->img == NULL)
		return (69);*/
	god->player = mlx_xpm_file_to_image(god->mlx, "us.xpm", &x, &x);
	mlx_put_image_to_window(god->mlx, god->win, god->player, 0, 0);
	mlx_hook(god->win, 17, 1L << 17, exit_button, god);
	mlx_key_hook(god->win, key_hook, god);
	mlx_loop_hook(god->mlx, render_next_frame, god);
	mlx_loop(god->mlx);
}