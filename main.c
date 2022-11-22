/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:34:41 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 17:31:02 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_window(t_map *map);

int main(int argc, char **argv)
{
	t_map map;
	t_map map_cpy;

	input_error(argc, argv);
	init_map(&map);
	init_map(&map_cpy);
	get_map(argv[1], &map);
	if (map.bitmap == NULL)
		empty_doc(&map);
	check_map(&map);	
	struct_cpy(&map_cpy, &map);	
	if (pathfinding(&map_cpy, map_cpy.player->x, map_cpy.player->y) == -1)
		no_path_error(&map, &map_cpy);
	free_map(&map_cpy);
	init_window(&map);	
	
	free_map(&map);
	return (0);
}

void init_window(t_map *map)
{
	void *mlx;
	void *mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->x*64, map->y*64, "./so_long");
	mlx_key_hook(mlx_win, key_hook, &map);
	
	mlx_loop(mlx);
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
