/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:45:52 by wchow             #+#    #+#             */
/*   Updated: 2024/05/17 21:21:07 by wchow            ###   ########.fr       */
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
	//Textures
	void	*player;
	void	*crew;
	void	*wall;
	void	*tile;
	void	*vent;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	//Semi Global Values
	int	collectibles; //just use this then minus off when collected ingame
	int	player_x;
	int	player_y;
	int	rows;
	int	cols;
	int	testX;
	int	testY;
	int	resX;
	int	resY;
}	t_god;

//Hooks
int	render_next_frame(t_god *god);

//Error Checking
int	check_map_validity(t_god *god);
int	check_collect_validity(t_god *god);
void	map_size(t_god *god);
void	find_player(t_god *god);
int	check_walls(t_god *god, int i, int j);
int	check_elements(t_god *god);
int	check_amounts(t_god *god, int p, int e, int c);
int	check_structure(t_god *god);

#endif