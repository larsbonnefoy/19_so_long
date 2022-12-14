/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:34:41 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/28 09:00:42 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sprites.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_map	map_cpy;
	t_data	data;
	int		fd;

	input_error(argc, argv);
	init_map(&map);
	data.map = &map;
	init_map(&map_cpy);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fd_error(&map);
	get_map(fd, &map);
	if (map.bitmap == NULL)
		empty_doc(&map);
	check_map(&map);
	struct_cpy(&map_cpy, &map);
	if (pathfinding(&map_cpy, map_cpy.player->x, map_cpy.player->y) == -1)
		no_path_error(&map, &map_cpy);
	free_map(&map_cpy);
	init_window(&map);
	return (0);
}
