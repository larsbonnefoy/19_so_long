/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:04 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 11:38:25 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sprites.h"

int check_end(t_map *map);

int	key_hook(int keycode, t_data *data)
{
	if(check_end(data->map) == 1)
		exit(1);
	if(keycode == 53)
		exit(1);	
	if(keycode == 13)
		move_up(data->map, 0);
	if(keycode == 1)
		move_down(data->map, 0);
	if(keycode == 2)
		move_right(data->map, 0);
	if(keycode == 0)
		move_left(data->map, 0);
	print_map(data->map);
	ft_printf("%d\n", data->map->player->mvt);
	print_map(data->map);
	load_map(data);
	return (0);
}

int check_end(t_map *map)
{
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
	{
		if (map->coll->amount == 0)
			return (1);
	}
	return (0);
}
