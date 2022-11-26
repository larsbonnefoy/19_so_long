/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:07:21 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 15:34:13 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int check_done_pfd(t_map *map);

int	pathfinding(t_map *map, int prev_pos_x, int prev_pos_y)
{
	int (*move[4])(t_map *map);
	int i;
	
	if (check_done_pfd(map) == 1)
		return (0);
	move[0] = &move_up_pfd;
	move[1] = &move_right_pfd;
	move[2] = &move_down_pfd;
	move[3] = &move_left_pfd;
	i = 0;
	while (i < 4)
	{
		map->bitmap[get_pos_str(map, prev_pos_x, prev_pos_y)] = 'P';
		if(move[i](map) == 1)
		{	
			pathfinding(map, map->player->x, map->player->y);
			//print_map(map);
			if (check_done_pfd(map) == 1)
				return (0);
			set_player_pos(map, get_pos_str(map, prev_pos_x, prev_pos_y));
		}
		i++;
	}	
	map->bitmap[get_pos_str(map, map->player->x, map->player->y)] = 'x';
	return (-1);
}

int check_done_pfd(t_map *map)
{
	if (map->exit->amount == 0 && map->coll->amount == 0) 
	{
		map->exit->status = 1;
		return (1);
	}
	return (0);

}
