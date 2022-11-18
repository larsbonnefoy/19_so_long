/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:22:12 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/18 13:32:06 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h" //inclure la librairie directement i guess au lieu d'inclure tous les .h
#include "19_libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>

typedef struct s_collectible {
	
	int amount;
}	t_coll;

typedef struct s_player {
	
	int		x;
	int		y;
	int 	status;
	int		amount;
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
#endif
