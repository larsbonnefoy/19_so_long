/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:39:04 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/21 18:31:13 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map *map)
{
	
	if(keycode == 13)
		move_up(map, 0);
	if(keycode == 1)
		move_down(map, 0);
	if(keycode == 2)
		move_right(map, 0);
	if(keycode == 0)
		move_left(map, 0);
	print_map(map);
	printf("Exit %d, Coll left, %d\n", map->exit->amount, map->coll->amount);
	return (0);
}
