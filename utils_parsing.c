/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:29:48 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 09:32:01 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_line(t_map *map,size_t pos_in_str)
{
	int line;

	line = pos_in_str/map->x;
	return(line);
}

int get_col(t_map *map, size_t pos_in_str)
{
	int col;

	col = pos_in_str%map->x;
	return(col);
}

size_t	get_pos_str(t_map *map, int x, int y)
{
 	size_t	pos;
	
	pos = (map->x)*y + x;
	return (pos);
}

void	set_player_pos(t_map *map, size_t pos_in_str)
{
	map->player->x = get_col(map, pos_in_str);
	map->player->y = get_line(map, pos_in_str);
	map->player->status = 1; 
}

void	set_exit_pos(t_map *map, size_t pos_in_str)
{
	map->exit->x = get_col(map, pos_in_str);
	map->exit->y = get_line(map, pos_in_str);
}
