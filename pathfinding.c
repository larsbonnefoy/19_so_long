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

int	pathfinding(t_data *dt, int prev_pos_x, int prev_pos_y)
{
	int (*move[4])(t_data *dt, int pfd);
	int i;
	
	if (check_done_pfd(dt->map) == 1)
		return (0);
	move[0] = &move_up;
	move[1] = &move_right;
	move[2] = &move_down;
	move[3] = &move_left;
	i = 0;
	while (i < 4)
	{
		dt->map->bitmap[get_pos_str(dt->map, prev_pos_x, prev_pos_y)] = 'P';
		if(move[i](dt, 1) == 1)
		{	
			pathfinding(dt, dt->map->player->x, dt->map->player->y);
			if (check_done_pfd(dt->map) == 1)
				return (0);
			set_player_pos(dt->map, get_pos_str(dt->map, prev_pos_x, prev_pos_y));
		}
		i++;
	}	
	dt->map->bitmap[get_pos_str(dt->map, dt->map->player->x, dt->map->player->y)] = 'x';
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
