/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:14:49 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/28 08:15:39 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "sprites.h"

void	empty_doc(t_map *map)
{
	ft_printf("Error\nEmpty doc\n");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	input_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of argumets provided\n");
		exit(EXIT_FAILURE);
	}	
	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
	{
		ft_printf("Error\nNot a .ber map file\n");
		exit(EXIT_FAILURE);
	}
}

void	fd_error(t_map *map)
{
	ft_printf("Error\nCould not open file");
	free_map(map);
	exit(EXIT_FAILURE);
}

void	sprit_error(t_data *data)
{
	ft_printf("Error\nCould not load sprite\n");
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map);
	exit(EXIT_FAILURE);
}

void	mlx_error(t_data *data, int error_nb)
{
	if (error_nb == 0)
	{
		ft_printf("Error\nMLX failed to open\n");
		free_map(data->map);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("Error\nMLX window failed to open\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_FAILURE);
	}	
}
