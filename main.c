/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:34:41 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 08:59:49 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map map;
	t_map map_cpy;
	void *mlx;
	void *mlx_win;

	(void) argc;
	init_map(&map);
	init_map(&map_cpy);
	get_map(argv[1], &map);
	check_map(&map);	
	struct_cpy(&map_cpy, &map);	
	if (pathfinding(&map_cpy, map_cpy.player->x, map_cpy.player->y) == -1)
	{	
		printf("No possible way out found\n");
		printf("Exit %d, Coll left, %d\n", map_cpy.exit->amount, map_cpy.coll->amount);
		exit(1);
	}
	free_map(&map_cpy);
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello World");
	mlx_key_hook(mlx_win, key_hook, &map);
	
	printf("Exit %d, Coll left, %d\n", map.exit->amount, map.coll->amount);
	
	mlx_loop(mlx);
	
	
	free_map(&map);
	return (0);
}

void print_map(t_map *map)
{
	int line;
	int col;

	line = 0;
	system("clear");
	while (line < map->y)
	{
		col = 0;
		printf("%d:		", line);
		while (col < map->x)	
		{	
			if (map->bitmap[line*map->x + col] == 'P')
				printf("\033[0;36m%c\e[m", 'P');
			else
				printf("%c", map->bitmap[line*map->x + col]);
			col++;
		}
		printf("\n");
		line++;
	}
	usleep(3000);
}
