/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:48:39 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/28 09:00:15 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sprites.h"
#include "errors.h"

void	load_map(t_data *data);
void	check_sprt(t_sprt *sprt, void *img, t_data *data, int to_free);
void	set_sprt_to_null(t_sprt *sprt);

void	init_window(t_map *map)
{
	void	*mlx;
	void	*win;
	t_data	data;

	mlx = mlx_init();
	if (mlx == NULL)
		mlx_error(&data, 0);
	win = mlx_new_window(mlx, map->x * 32, map->y * 32, "./so_long");
	if (win == NULL)
		mlx_error(&data, 1);
	data.mlx = mlx;
	data.win = win;
	data.map = map;
	data.sprt = init_sprt(&data);
	load_map(&data);
	mlx_key_hook(win, key_hook, &data);
	mlx_hook(data.win, 17, 0, free_exit_so_long, &data);
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
	sprt->spr[0] = mlx_xpm_file_to_image(data->mlx, "./img/p_r", &wth, &hgt);
	check_sprt(sprt, sprt->spr[0], data, 1);
	sprt->spr[1] = mlx_xpm_file_to_image(data->mlx, "./img/coll", &wth, &hgt);
	check_sprt(sprt, sprt->spr[1], data, 2);
	sprt->spr[2] = mlx_xpm_file_to_image(data->mlx, "./img/wall", &wth, &hgt);
	check_sprt(sprt, sprt->spr[2], data, 3);
	sprt->spr[3] = mlx_xpm_file_to_image(data->mlx, "./img/e_c", &wth, &hgt);
	check_sprt(sprt, sprt->spr[3], data, 4);
	sprt->spr[4] = mlx_xpm_file_to_image(data->mlx, "./img/clear", &wth, &hgt);
	check_sprt(sprt, sprt->spr[4], data, 5);
	return (sprt);
}

void	check_sprt(t_sprt *sprt, void *img, t_data *data, int to_free)
{	
	int	i;

	i = 0;
	if (img == NULL)
	{
		while (i < to_free)
		{
			free(sprt->spr[i]);
			i++;
		}
		sprit_error(data);
	}
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
