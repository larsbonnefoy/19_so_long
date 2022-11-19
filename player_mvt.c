/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:25:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/18 12:36:42 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_map *map, size_t start, size_t end, int pfd);

int	move_up(t_map *map, int pfd)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start - (size_t)(map->x);
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		return (move_player(map, pos_start, pos_end, pfd));
	if (map->bitmap[pos_end] == 'C')
		return (move_player(map, pos_start, pos_end, pfd));
	return (1);
}

int move_down(t_map *map, int pfd)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start + (size_t)(map->x);
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		return (move_player(map, pos_start, pos_end, pfd));
	if (map->bitmap[pos_end] == 'C')
		return (move_player(map, pos_start, pos_end, pfd));
	return (1);
}

int move_left(t_map *map, int pfd)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start - 1;
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		return (move_player(map, pos_start, pos_end, pfd));
	if (map->bitmap[pos_end] == 'C')
		return (move_player(map, pos_start, pos_end, pfd));
	return (1);
}

int	move_right(t_map *map, int pfd)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start + 1;
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		return (move_player(map, pos_start, pos_end, pfd));
	if (map->bitmap[pos_end] == 'C')
		return (move_player(map, pos_start, pos_end, pfd));
	return (1);
}

int  move_player(t_map *map, size_t start, size_t end, int pfd)
{
	if(map->bitmap[end] == 'C')
		map->coll->amount-=1;
	if(map->bitmap[end] == 'E')
		map->exit->amount-=1;
	if (pfd == 0)
	{
		if (map->player->x == map->exit->x && map->player->y == map->exit->y)
		{
			map->bitmap[start] = 'E';
			map->bitmap[end] = 'P';
		}
		else
		{
			map->bitmap[start] = '0';
			map->bitmap[end] = 'P';
		}
	}
	if (pfd == 1)
	{
		map->bitmap[start] = 'x';
		map->bitmap[end] = 'P';
	}
	set_player_pos(map, end);
	return (check_done(map));
}
