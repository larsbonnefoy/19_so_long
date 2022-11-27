/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:25:32 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 17:01:48 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sprites.h"

void	move_player(t_data *data, size_t *pos);

int	move_up(t_data *data)
{
	size_t		pos_beg;
	size_t		pos_end;
	size_t		pos[2];
	t_player	*player;

	player = data->map->player;
	pos_beg = get_pos_str(data->map, player->x, player->y);
	pos_end = pos_beg - (size_t)(data->map->x);
	pos[0] = pos_beg;
	pos[1] = pos_end;
	if (data->map->bitmap[pos_end] == '1' || data->map->bitmap[pos_end] == 'x')
		return (0);
	if (data->map->bitmap[pos_end] == 'E' || data->map->bitmap[pos_end] == '0')
		move_player(data, pos);
	if (data->map->bitmap[pos_end] == 'C')
	{
		data->map->coll->amount -= 1;
		move_player(data, pos);
	}
	return (1);
}

int	move_down(t_data *data)
{
	size_t		pos_beg;
	size_t		pos_end;
	size_t		pos[2];
	t_player	*player;

	player = data->map->player;
	pos_beg = get_pos_str(data->map, player->x, player->y);
	pos_end = pos_beg + (size_t)(data->map->x);
	pos[0] = pos_beg;
	pos[1] = pos_end;
	if (data->map->bitmap[pos_end] == '1' || data->map->bitmap[pos_end] == 'x')
		return (0);
	if (data->map->bitmap[pos_end] == 'E' || data->map->bitmap[pos_end] == '0')
		move_player(data, pos);
	if (data->map->bitmap[pos_end] == 'C')
	{
		data->map->coll->amount -= 1;
		move_player(data, pos);
	}
	return (1);
}

int	move_left(t_data *data)
{
	size_t		pos_beg;
	size_t		pos_end;
	size_t		pos[2];
	t_player	*player;

	player = data->map->player;
	pos_beg = get_pos_str(data->map, player->x, player->y);
	pos_end = pos_beg - 1;
	pos[0] = pos_beg;
	pos[1] = pos_end;
	if (data->map->bitmap[pos_end] == '1' || data->map->bitmap[pos_end] == 'x')
		return (0);
	if (data->map->bitmap[pos_end] == 'E' || data->map->bitmap[pos_end] == '0')
		move_player(data, pos);
	if (data->map->bitmap[pos_end] == 'C')
	{
		data->map->coll->amount -= 1;
		move_player(data, pos);
	}
	return (1);
}

int	move_right(t_data *data)
{
	size_t		pos_beg;
	size_t		pos_end;
	size_t		pos[2];
	t_player	*player;

	player = data->map->player;
	pos_beg = get_pos_str(data->map, player->x, player->y);
	pos_end = pos_beg + 1;
	pos[0] = pos_beg;
	pos[1] = pos_end;
	if (data->map->bitmap[pos_end] == '1' || data->map->bitmap[pos_end] == 'x')
		return (0);
	if (data->map->bitmap[pos_end] == 'E' || data->map->bitmap[pos_end] == '0')
		move_player(data, pos);
	if (data->map->bitmap[pos_end] == 'C')
	{
		data->map->coll->amount -= 1;
		move_player(data, pos);
	}
	return (1);
}

void	move_player(t_data *data, size_t *pos)
{
	t_map	*map;
	int		prev_ext;

	map = data->map;
	if (map->bitmap[pos[1]] == 'E')
		map->exit->amount = 0;
	prev_ext = 0;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
	{
		prev_ext = 1;
		set_char_map(&map->bitmap[pos[0]], &map->bitmap[pos[1]], 'E', 'P');
	}
	else
		set_char_map(&map->bitmap[pos[0]], &map->bitmap[pos[1]], '0', 'P');
	map->player->mvt += 1;
	set_player_pos(map, pos[1]);
	draw_sprt(data, pos[0], prev_ext);
}
