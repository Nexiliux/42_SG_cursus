/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:45:52 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 20:53:44 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "../mlx_linux/mlx.h"
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../printf/includes/ft_printf.h"

#define WIDTH 1280
#define HEIGHT 720

typedef struct s_god
{
	//MLX innit
	void	*mlx;
	void	*win;
	char	**map;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	//Textures
	void	*player;
	void	*crew;
	void	*wall;
	void	*tile;
	void	*vent_closed;
	void	*vent_open;
	//Semi Global Values
	int	collectibles; //just use this then minus off when collected ingame
	int	player_x; //Player starting pos in map ints e.g. (3, 0)
	int	player_y; //Player starting pos in map ints e.g. (0, 3)
	int	rows; //Map size in ROWS, meaning Y axis
	int	cols; //Map size in COLS meaning X axis
	int	testX; //Player X pos in pixels
	int	testY; //Player Y pos in pixels
	int	resX; //starting Resolutions
	int	resY;
	int	exit; //for floodfill to find exit
	int	moves; //# of moves
}	t_god;

//Hooks
int	exit_button(t_god *god);
int	key_hook(int keycode, t_god *god);

//Error Checking
char	**parse_map(char *arg);
int	check_map_validity(t_god *god);
int	check_collect_validity(t_god *god);
void	find_player(t_god *god);
void	map_size(t_god *god);
int	floodfill(char **map, int x, int y, t_god *god);
//int	floodfill_exit(char **map, int x, int y, t_god *god);
void	map_size(t_god *god);
void	find_player(t_god *god);
int	check_walls(t_god *god, int i, int j);
int	check_elements(t_god *god);
int	check_amounts(t_god *god, int p, int e, int c);
int	check_structure(t_god *god);

//Map Logic
void	update_map(t_god *god, int px, int py);
void	check_collision(t_god *god, int px, int py, int keycode);

//Rendering
void	load_textures(t_god *god, int i);
void	draw_map(t_god *god, int i, int j);
int	render_next_frame(t_god *god);

//Misc
void	god_init(t_god *god);
void	exit_game(t_god *god, int maprows);

#endif