/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:22:12 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 15:33:02 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "gnl/get_next_line.h" //inclure la librairie directement i guess au lieu d'inclure tous les .h
#include "19_libft/libft.h"
#include "19_ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>


typedef struct s_sprites
{
	int		i_w;
	int		i_h;
	void	*p_r;
	void	*cl;
	void	*wl;
	void	*e_o;
	void	*e_c;
	void	*clear;
}	t_sprt;

typedef struct s_collectible {
	
	int amount;
}	t_coll;

typedef struct s_player {
	
	int		x;
	int		y;
	int 	status;
	int		amount;
	int		mvt;
}	t_player;

typedef struct s_exit {
	
	int		x;
	int		y;
	int		status;
	int		amount;
}	t_exit;


typedef struct s_map {

	char		*bitmap;
	int			x;
	int 		y;
	t_player	*player;
	t_exit		*exit;
	t_coll		*coll;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_sprt	*sprt;

}	t_data;

void print_map(t_map *map);

void	get_map(char *name, t_map *map);
void	check_map(t_map *map);
int		get_line(t_map *map, size_t pos_in_str);
int		get_col(t_map *map, size_t pos_in_str);
size_t	get_pos_str(t_map *map, int x, int y);
void	init_map(t_map *map);
void	set_player_pos(t_map *map, size_t pos_in_str);
void	set_exit_pos(t_map *map, size_t pos_in_str);

int		move_up(t_data *data);
int		move_up_pfd(t_map *map);
int		move_down(t_data *data);
int		move_down_pfd(t_map *map);
int		move_left(t_data *data);
int		move_left_pfd(t_map *map);
int		move_right(t_data *data);
int		move_right_pfd(t_map *map);

int		pathfinding(t_map *map, int prev_pos_x, int prev_pos_y);
int		check_done_pfd(t_map *map);

void 	struct_cpy(t_map *map_cpy, t_map *map);
void	free_map(t_map *map);

int		key_hook(int keycode, t_data *data);

#endif
