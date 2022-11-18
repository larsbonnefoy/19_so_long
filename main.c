/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:34:41 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/18 13:35:00 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map map;
	//int pfd = 1;
	(void) argc;
	(void) argv;
	init_map(&map);
	get_map(argv[1], &map);
	check_map(&map);	
	print_map(&map);
	printf("--------------------------\n");
	/*
	move_up(&map, pfd);	
	print_map(&map);
	printf("--------------------------\n");
	move_right(&map, pfd);	
	print_map(&map);
	printf("--------------------------\n");
	move_down(&map, pfd);	
	print_map(&map);
	printf("--------------------------\n");
	move_left(&map, pfd);	
	*/
	pathfinding(&map, map.player->x, map.player->y);
	print_map(&map);
	printf("EXIT %d, Coll left, %d\n", map.exit->amount, map.coll->amount);
		
	free(map.bitmap);
	return (0);
}

void print_map(t_map *map)
{
	int line;
	int col;

	line = 0;
	while (line < map->y)
	{
		col = 0;
		printf("%d:		", line);
		while (col < map->x)	
		{	
			printf("%c", map->bitmap[line*map->x + col]);
			col++;
		}
		printf("\n");
		line++;
	}
}
