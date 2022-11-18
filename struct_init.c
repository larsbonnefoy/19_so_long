/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:54:56 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/17 14:29:34 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player *init_player();
t_exit *init_exit();
t_coll *init_coll(); 

void init_map(t_map *map)
{
	map->bitmap = NULL;
	map->x = 0;
	map->y = 0;
	map->player = init_player();
	map->exit = init_exit();
	map->coll = init_coll();
}

t_player *init_player()
{
	t_player *player;
	
	player = malloc(sizeof(t_player));
	if (!player)
		exit(1);
	player->x = 0;
	player->y = 0;
	player->status = 0;
	player->amount = 0;
	return (player);
}

t_exit *init_exit()
{
	t_exit *exit_map;
	
	exit_map = malloc(sizeof(t_player));
	if (!exit_map)
		exit(1);
	exit_map->x = 0;
	exit_map->y = 0;
	exit_map->status = 0;
	exit_map->amount = 0;
	return (exit_map);
}

t_coll *init_coll()
{
	t_coll *coll;

	coll = malloc(sizeof(t_coll));
	if (!coll)
		exit(1);
	coll->amount = 0;
	return (coll);
}
