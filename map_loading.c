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

void load_map(t_data *data);

void init_window(t_map *map)
{
	void *mlx;
	void *win;
	t_data data;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, map->x*32, map->y*32, "./so_long");
	data.mlx = mlx;
	data.win = win;
	data.map = map;
	data.sprt = init_sprt(&data);	
	load_map(&data);	
	mlx_key_hook(win, key_hook, &data);
	
	mlx_loop(mlx);
}

t_sprt *init_sprt(t_data *data)
{
	t_sprt *sprt;
	int	hgt;
	int wth;

	sprt = malloc(sizeof(t_sprt));
	if (!(sprt))
		exit(1);
	hgt = sprt->i_h;
	wth = sprt->i_w;
	sprt->p_r = mlx_xpm_file_to_image(data->mlx, "./img/p_r", &wth, &hgt);
	sprt->cl = mlx_xpm_file_to_image(data->mlx, "./img/coll", &wth, &hgt);
	sprt->wl = mlx_xpm_file_to_image(data->mlx, "./img/wall", &wth, &hgt);
	sprt->e_o = mlx_xpm_file_to_image(data->mlx, "./img/e_o", &wth, &hgt);
	sprt->e_c = mlx_xpm_file_to_image(data->mlx, "./img/e_c", &wth, &hgt);
	sprt->clear = mlx_xpm_file_to_image(data->mlx, "./img/clear", &wth, &hgt);
	return (sprt);
}

void load_map(t_data *data)
{
	size_t	i;
	
	i= 0;
	while (data->map->bitmap[i] != '\0')
	{
		if (data->map->bitmap[i] == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->sprt->wl, get_col(data->map, i)*32, get_line(data->map, i)*32);	
		if (data->map->bitmap[i] == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->sprt->p_r, get_col(data->map, i)*32, get_line(data->map, i)*32);	
		if (data->map->bitmap[i] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->sprt->cl, get_col(data->map, i)*32, get_line(data->map, i)*32);	
		if (data->map->bitmap[i] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->sprt->e_c, get_col(data->map, i)*32, get_line(data->map, i)*32);	
		i++;
	}
}

void put_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprt->p_r, x*32, y*32);	
}

void clear(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprt->clear, x*32, y*32);	
}

void put_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->sprt->e_c, x*32, y*32);	
}

void draw_sprt(t_data *data, size_t prev_pos, int prev_ext)
{
	if (prev_ext == 1)
	{
		put_player(data, data->map->player->x, data->map->player->y);
		clear(data, get_col(data->map, prev_pos), get_line(data->map, prev_pos));	
		put_exit(data, get_col(data->map, prev_pos), get_line(data->map, prev_pos));	
	}
	else
	{
		put_player(data, data->map->player->x, data->map->player->y);
		clear(data, get_col(data->map, prev_pos), get_line(data->map, prev_pos));	
	}
}
