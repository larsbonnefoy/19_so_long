/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:22:12 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:02 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h" //inclure la librairie directement i guess au lieu d'inclure tous les .h
#include "19_libft/libft.h"
#include "19_ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
#define FAILURE 1

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

void print_map(t_map *map);

void	get_map(char *name, t_map *map);
void	check_map(t_map *map);
int		get_line(t_map *map, size_t pos_in_str);
int		get_col(t_map *map, size_t pos_in_str);
size_t	get_pos_str(t_map *map, int x, int y);
void	init_map(t_map *map);
void	set_player_pos(t_map *map, size_t pos_in_str);
void	set_exit_pos(t_map *map, size_t pos_in_str);

int		move_up(t_map *map, int pfd);
int		move_down(t_map *map, int pfd);
int		move_left(t_map *map, int pfd);
int		move_right(t_map *map, int pfd);

int		pathfinding(t_map *map, int prev_pos_x, int prev_pos_y);
int		check_done_pfd(t_map *map);

void 	struct_cpy(t_map *map_cpy, t_map *map);
void	free_map(t_map *map);

int		key_hook(int keycode, t_map *map);

void 	line_error(t_map *map, char *str);
void	token_error(t_map *map);
void	no_path_error(t_map *map, t_map *map_cpy);
void	wall_error(t_map *map, int x, int y);
void	wrong_char(t_map *map, int x, int y);
void	empty_doc(t_map *map);
void	input_error(int argc, char **argv);
#endif
