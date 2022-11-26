#include "so_long.h"
#include "sprites.h"

void	put_player(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->sprt->p_r, x * 32, y * 32);
}

void	clear(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->sprt->clear, x * 32, y * 32);
}

void	put_exit_c(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->sprt->e_c, x * 32, y * 32);
}

void	draw_sprt(t_data *data, size_t prev_pos, int prev_ext)
{
	int	x;
	int	y;

	y = get_line(data->map, prev_pos);
	x = get_col(data->map, prev_pos);
	if (prev_ext == 1)
	{
		put_player(data, data->map->player->x, data->map->player->y);
		clear(data, x, y);
		put_exit_c(data, x, y);
	}
	else
	{
		put_player(data, data->map->player->x, data->map->player->y);
		clear(data, x, y);
	}
}
