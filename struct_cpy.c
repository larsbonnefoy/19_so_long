/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:08:14 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 09:20:27 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void struct_cpy(t_map *map_cpy, t_map *map)
{
	map_cpy->bitmap = ft_strdup(map->bitmap);
	if (map_cpy->bitmap == NULL)
		exit(1);
	map_cpy->x = map->x;
	map_cpy->y = map->y;
	map_cpy->player->x = map->player->x;
	map_cpy->player->y = map->player->y;
	map_cpy->player->status = map->player->status;
	map_cpy->player->amount = map->player->amount;
	map_cpy->player->mvt= map->player->mvt;
	map_cpy->exit->x = map->exit->x;
	map_cpy->exit->y = map->exit->y;
	map_cpy->exit->status = map->exit->status;
	map_cpy->exit->amount = map->exit->amount;
	map_cpy->coll->amount = map->coll->amount;
}

void free_map(t_map *map)
{
	free(map->bitmap);
	free(map->player);
	free(map->exit);
	free(map->coll);
}
