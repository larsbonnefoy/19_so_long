/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:07:21 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/18 13:35:50 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pathfinding(t_map *map, int prev_pos_x, int prev_pos_y)
{
	int (*move[4])(t_map *map, int pfd);
	int i;
	int tmp_pos_x;
	int tmp_pos_y;

	move[0] = &move_up;
	move[1] = &move_right;
	move[2] = &move_down;
	move[3] = &move_left;
	tmp_pos_x = map->player->x;
	tmp_pos_y = map->player->y;
	i = 0;
	while (i < 4)
	{
		if(move[i](map, 1) == 1)
			pathfinding(map, tmp_pos_x ,tmp_pos_y);
		else
		{
		 	map->player->x = prev_pos_x;
			map->player->y = prev_pos_y;
			return (0);//si jamais on return 0 il faut reset la position du joueur a la precedente
		}
		i++;
	}
	return (0);
}

