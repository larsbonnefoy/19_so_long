/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:15:39 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/24 16:53:07 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
#define SPRITES_H

#include "so_long.h"
#include "mlx/mlx.h"


void load_map(t_data *data);
void init_window(t_map *map);
t_sprt *init_sprt(t_data *data);
void put_player(t_data *data, int x, int y);
void clear(t_data *data, int x, int y);
void put_exit(t_data *data, int x, int y);
void draw_sprt(t_data *data, size_t prev_pos, int prev_ext);

#endif

