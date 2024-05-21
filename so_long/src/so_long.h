/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:45:52 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 15:39:12 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"

typedef struct s_god
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*player;
	void	*crew;
	void	*wall;
	void	*tile;
	void	*vent_closed;
	void	*vent_open;

	int		collectibles;
	int		player_x;
	int		player_y;
	int		rows;
	int		cols;
	int		test_x;
	int		test_y;
	int		res_x;
	int		res_y;
}	t_god;

//Hooks
int		exit_button(t_god *god);
int		key_hook(int keycode, t_god *god);

//Error Checking
char	**parse_map(char *arg);
int		check_map_validity(t_god *god);
int		check_collect_validity(t_god *god);
void	map_size(t_god *god);
void	find_player(t_god *god);
int		check_walls(t_god *god, int i, int j);
int		check_elements(t_god *god);
int		check_amounts(t_god *god, int p, int e, int c);
int		check_structure(t_god *god);

//Map Logic
void	update_map(t_god *god, int px, int py);
void	check_collision(t_god *god, int px, int py, int keycode);

//Rendering
void	load_textures(t_god *god, int i);
void	draw_map(t_god *god, int i, int j);
int		render_next_frame(t_god *god);

//Misc
void	god_init(t_god *god);
void	exit_game(t_god *god, int maprows);

#endif