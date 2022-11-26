/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:48:39 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 17:02:30 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sprites.h"

void	load_map(t_data *data);

void	init_window(t_map *map)
{
	void	*mlx;
	void	*win;
	t_data	data;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->x * 32, map->y * 32, "./so_long");
	data.mlx = mlx;
	data.win = win;
	data.map = map;
	data.sprt = init_sprt(&data);
	load_map(&data);
	mlx_key_hook(win, key_hook, &data);
	mlx_loop(mlx);
}

t_sprt	*init_sprt(t_data *data)
{
	t_sprt	*sprt;
	int		hgt;
	int		wth;

sprt = malloc(sizeof(t_sprt));
	if (!(sprt))
		exit(1);
	hgt = sprt->i_h;
	wth = sprt->i_w;
	sprt->p_r = mlx_xpm_file_to_image(data->mlx, "./img/p_r", &wth, &hgt);
	sprt->cl = mlx_xpm_file_to_image(data->mlx, "./img/coll", &wth, &hgt);
	sprt->wl = mlx_xpm_file_to_image(data->mlx, "./img/wall", &wth, &hgt);
	sprt->e_c = mlx_xpm_file_to_image(data->mlx, "./img/e_c", &wth, &hgt);
	sprt->clear = mlx_xpm_file_to_image(data->mlx, "./img/clear", &wth, &hgt);
	return (sprt);
}

void	load_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map->bitmap[i] != '\0')
	{
		if (data->map->bitmap[i] == '1')
			put_wall(data, get_col(data->map, i), get_line(data->map, i));
		if (data->map->bitmap[i] == 'P')
			put_player(data, get_col(data->map, i), get_line(data->map, i));
		if (data->map->bitmap[i] == 'C')
			put_coll(data, get_col(data->map, i), get_line(data->map, i));
		if (data->map->bitmap[i] == 'E')
			put_exit_c(data, get_col(data->map, i), get_line(data->map, i));
		i++;
	}
}
