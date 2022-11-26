/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:39:03 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/22 17:04:19 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "errors.h"

void	check_map(t_map *map);
size_t	check_wall(t_map *map, size_t pos);
void	add_tokens(t_map *map, size_t pos);

void	get_map(char *map_file, t_map *map)
{
	char	*new_line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		fd_error(map);
	while (1)
	{
		new_line= get_next_line(fd);
		if (new_line == NULL)
			return ;
		if (ft_strlen(new_line) < 4)
			line_error(map, new_line);
		new_line = ft_strtrimf(new_line, "\n");
		if (!new_line)
			return ;
		if (map->y == 0)
		{	
			map->x = ft_strlen(new_line);
			map->y += 1;
			map->bitmap = new_line;
		}
		else
		{	
			if ((int)ft_strlen(new_line) != map->x)
				line_error(map, new_line);
			map->bitmap = ft_strjoinf(map->bitmap, new_line);
			map->y += 1;
			free(new_line);
		}
	}
}

void	check_map(t_map *map)
{
	size_t	pos;
	int		c_amount;
	int		p_amount;
	int		e_amount;

	pos = 0;
	while (pos < (size_t)(map->x * map->y) - 1)
	{
		pos = check_wall(map, pos);
		add_tokens(map, pos);
		pos++;
	}
	c_amount = map->coll->amount;
	p_amount = map->player->amount;
	e_amount = map->exit->amount;
	if (c_amount == 0 || p_amount != 1 || e_amount != 1)
		token_error(map);
}

size_t	check_wall(t_map *map, size_t pos)
{
	int		y;

	y = get_line(map, pos);
	while ((y == 0 || y == map->y - 1) && pos < (size_t)(map->x * map->y) - 1)
	{
		if (map->bitmap[pos] == '1')
		{
			pos++;
			y = get_line(map, pos);
		}	
		else
			wall_error(map, get_col(map, pos), get_line(map, pos));
	}
	if ((get_col(map, pos) == 0 || get_col(map, pos) == map->x-1))
	{
		if (map->bitmap[pos] != '1')
			wall_error(map, get_col(map, pos), get_line(map, pos));
	}
	return (pos);
}

void	add_tokens(t_map *map, size_t pos)
{
	if (map->bitmap[pos] == 'P')
	{	
		set_player_pos(map, pos);
		map->player->amount += 1;
	}	
	if (map->bitmap[pos] == 'C')
		map->coll->amount += 1;
	if (map->bitmap[pos] == 'E')
	{
		set_exit_pos(map, pos);
		map->exit->amount += 1;
	}
	if (ft_strchr("10PCE", map->bitmap[pos]) == NULL)
		wrong_char(map, get_col(map, pos), get_line(map, pos));
	if (map->player->amount > 1 || map->exit->amount > 1)
		token_error(map);
}
