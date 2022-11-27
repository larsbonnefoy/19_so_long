#include "so_long.h"
#include "sprites.h"

void	put_wall(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->sprt->spr[2], x * 32, y * 32);
}

void	put_coll(t_data *data, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx;
	win = data->win;
	mlx_put_image_to_window(mlx, win, data->sprt->spr[1], x * 32, y * 32);
}
