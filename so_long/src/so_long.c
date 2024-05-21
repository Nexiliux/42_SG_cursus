/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:21 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 15:39:12 by wchow            ###   ########.fr       */
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
		if (keycode == XK_w && (god->test_y - 64 >= 0))
			god->test_y -= 64;
		if (keycode == XK_s && (god->test_y + 64 <= god->res_y - 64))
			god->test_y += 64;
		if (keycode == XK_a && (god->test_x - 64 >= 0))
			god->test_x -= 64;
		if (keycode == XK_d && (god->test_x + 64 <= god->res_x - 64))
			god->test_x += 64;
		check_collision(god, god->test_x / 64, god->test_y / 64, keycode);
		update_map(god, god->test_x / 64, god->test_y / 64);
		render_next_frame(god);
	}
	return (0);
}

char	**parse_map(char *arg)
{
	int		i;
	int		fd;
	char	*line;
	char	**result;

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
	god->res_x = 64 * god->cols;
	god->res_y = 64 * god->rows;
	god->test_x = 64 * god->player_x;
	god->test_y = 64 * god->player_y;
	god->mlx = mlx_init();
	god->win = mlx_new_window(god->mlx, god->res_x, god->res_y, "yo");
	load_textures(god, 64);
	render_next_frame(god);
	mlx_hook(god->win, 17, 1L << 17, exit_button, god);
	mlx_key_hook(god->win, key_hook, god);
	mlx_loop(god->mlx);
}
