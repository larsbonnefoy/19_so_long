/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:25:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 09:43:41 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_map *map, size_t start, size_t end, int pfd);
void set_char_map(char *start_str, char *end_str, char start, char end);

int	move_up(t_map *map, int pfd)
{
	size_t pos_start;
	size_t pos_end;
	
	pos_start = get_pos_str(map, map->player->x, map->player->y);
	pos_end = pos_start - (size_t)(map->x);
	if (map->bitmap[pos_end] == '1' || map->bitmap[pos_end] == 'x')
		return (0);
	if (map->bitmap[pos_end] == 'E' || map->bitmap[pos_end] == '0')
		move_player(map, pos_start, pos_end, pfd);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player(map, pos_start, pos_end, pfd);
	}
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
		move_player(map, pos_start, pos_end, pfd);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player(map, pos_start, pos_end, pfd);
	}
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
		move_player(map, pos_start, pos_end, pfd);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player(map, pos_start, pos_end, pfd);
	}
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
		move_player(map, pos_start, pos_end, pfd);
	if (map->bitmap[pos_end] == 'C')
	{
		map->coll->amount-=1;
		move_player(map, pos_start, pos_end, pfd);
	}	
	return (1);
}

void  move_player(t_map *map, size_t start, size_t end, int pfd)
{
	if(map->bitmap[end] == 'E')
		map->exit->amount = 0;
	if (pfd == 0)
	{
		if (map->player->x == map->exit->x && map->player->y == map->exit->y)
			set_char_map(&map->bitmap[start], &map->bitmap[end], 'E', 'P');
		else
			set_char_map(&map->bitmap[start], &map->bitmap[end], '0', 'P');
		map->player->mvt += 1;
	}
	if (pfd == 1)
		set_char_map(&map->bitmap[start], &map->bitmap[end], 'x', 'P');
	set_player_pos(map, end);
}

void set_char_map(char *start_str, char *end_str, char start, char end)
{
	*start_str = start;
	*end_str = end;
}
