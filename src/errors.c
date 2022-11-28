/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:21:07 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/28 09:22:39 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"errors.h"

void	wall_error(t_map *map, int x, int y)
{
	ft_printf("Error\nWall missing at [%d:%d]\n", x, y);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	wrong_char(t_map *map, int x, int y)
{
	ft_printf("Error\nUnvalid char at [%d:%d]\n", x, y);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	token_error(t_map *map)
{
	ft_printf("Error\nUnvalid Token amount\nColl = %d\n", map->coll->amount);
	ft_printf("Player = %d\n", map->player->amount);
	ft_printf("Exit = %d\n", map->exit->amount);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	line_error(t_map *map, char *str)
{
	free(str);
	ft_printf("Error\nMap is not a square\n");
	if (map->y != 0)
	{
		free_map(map);
	}
	else
	{
		free(map->player);
		free(map->coll);
		free(map->exit);
	}
	exit(EXIT_FAILURE);
}

void	no_path_error(t_map *map, t_map *map_cpy)
{
	ft_printf("Error\nNo possible path found\n");
	free_map(map);
	free_map(map_cpy);
	exit(EXIT_FAILURE);
}
