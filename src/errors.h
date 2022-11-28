/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:16:25 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/28 09:24:58 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "so_long.h"

void	token_error(t_map *map);
void	no_path_error(t_map *map, t_map *map_cpy);
void	wall_error(t_map *map, int x, int y);
void	wrong_char(t_map *map, int x, int y);
void	empty_doc(t_map *map);
void	input_error(int argc, char **argv);
void	line_error(t_map *map, char *str);
void	fd_error(t_map *map);
void	sprit_error(t_data *data);
void	mlx_error(t_data *data, int error_nb);

#endif
