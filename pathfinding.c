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

int check_done(t_map *map);

int	pathfinding(t_map *map, int prev_pos_x, int prev_pos_y)
{
	int (*move[4])(t_map *map, int pfd);
	int i;

	move[0] = &move_up;
	move[1] = &move_right;
	move[2] = &move_down;
	move[3] = &move_left;
	i = 0;
	while (i < 4)
	{
		map->bitmap[get_pos_str(map, prev_pos_x, prev_pos_y)] = 'P';
		//printf("------x=%d-y=%d-i=%d------\n", map->player->x, map->player->y, i);
		//print_map(map);
		if(move[i](map, 1) == 1)
		{	
			pathfinding(map, map->player->x, map->player->y);
			if (check_done(map) == 2)
				return (0);
		}
		i++;
		map->player->x = prev_pos_x;
		map->player->y = prev_pos_y;
	}
	map->bitmap[get_pos_str(map, map->player->x, map->player->y)] = 'x';
	return (0);
}

int check_done(t_map *map)
{
	if (map->exit->amount == 0 && map->coll->amount == 0)
	{
		map->exit->status = 1;
		return (2);
	}
	return (1);
}

