/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:04 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 09:43:44 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_end(t_map *map);

int	key_hook(int keycode, t_map *map)
{
	if(check_end(map) == 1)
		exit(1);
	if(keycode == 53)
		exit(1);	
	if(keycode == 13)
		move_up(map, 0);
	if(keycode == 1)
		move_down(map, 0);
	if(keycode == 2)
		move_right(map, 0);
	if(keycode == 0)
		move_left(map, 0);
	print_map(map);
	ft_printf("%d\n", map->player->mvt);
	printf("Exit %d, Coll left, %d\n", map->exit->amount, map->coll->amount);
	printf("keycode == %d\n", keycode);
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
