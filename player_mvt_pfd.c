/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:25:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 08:50:08 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player_pfd(t_map *map, size_t start, size_t end);
void set_char_map_pfd(char *start_str, char *end_str, char start, char end);

int	move_up_pfd(t_map *map)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start - (size_t)(map->x);
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		move_player_pfd(map, pos_start, pos_end);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player_pfd(map, pos_start, pos_end);
	}
	return (1);
}

int move_down_pfd(t_map *map)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start + (size_t)(map->x);
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		move_player_pfd(map, pos_start, pos_end);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player_pfd(map, pos_start, pos_end);
	}
	return (1);
}

int move_left_pfd(t_map *map)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start - 1;
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		move_player_pfd(map, pos_start, pos_end);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player_pfd(map, pos_start, pos_end);
	}
	return (1);
}

int	move_right_pfd(t_map *map)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start + 1;
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		move_player_pfd(map, pos_start, pos_end);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player_pfd(map, pos_start, pos_end);
	}	
	return (1);
}

void  move_player_pfd(t_map *map, size_t start, size_t end)
{
	if(map->bitmap[end] == 'E')
		map->exit->amount = 0;
	set_char_map_pfd(&map->bitmap[start], &map->bitmap[end], 'x', 'P');
	set_player_pos(map, end);
}

void set_char_map_pfd(char *start_str, char *end_str, char start, char end)
{
	*start_str = start;
	*end_str = end;
}
