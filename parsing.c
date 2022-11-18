/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:39:03 by lbonnefo          #+#    #+#             */
/*   Updated: 2022/11/17 10:24:13 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *map);
size_t	check_wall(t_map *map, size_t pos);
void 	add_tokens(t_map *map, size_t pos);

void get_map(char *map_file, t_map *map)
{
	char *new_line;
	int fd;

	fd = open(map_file, O_RDONLY);	
	if (fd == -1)//erreur d'open
		return ;
	while (1)
	{
		new_line= get_next_line(fd);
		if (!new_line)
			return ;	
		if (ft_strlen(new_line) < 3)
		{
			printf("pas assez de lignes pour faire une carte");
			free(new_line);
			exit(1);
		}
		new_line = ft_strtrimf(new_line, "\n"); //free dans strtrim
		if (!new_line)
			return ;
		if (map->y == 0)//on est a la premiere ligne
		{	
			map->x = ft_strlen(new_line);
			map->y += 1;
			map->bitmap = new_line; //creer une copie?
		}
		else
		{	
			if ((int)ft_strlen(new_line) != map->x) //lq premiere ligne est quand meme stored => en cas d'erreur ici tout free;
				return ;
			map->bitmap = ft_strjoinf(map->bitmap, new_line); 
			map->y += 1;
		}
	}
}

void check_map(t_map *map)
{
	size_t pos;
	
	pos = 0;
	while(pos < (size_t)(map->x*map->y) - 1)
	{
		pos = check_wall(map, pos);		
		add_tokens(map, pos);
		pos++;		
	}
	if (map->coll->amount == 0 || map->player->amount != 1 || map->exit->amount != 1)
	{
		printf("EXIT Coll: %d player: %d exit: %d", map->coll->amount, map->player->amount, map->exit->amount);
		exit (1);
	}
}

size_t  check_wall(t_map *map, size_t pos)
{
	while ((get_line(map, pos) == 0 || get_line(map, pos) == map->y - 1) && pos < (size_t)(map->x*map->y) -1) 
	{
		if(map->bitmap[pos] == '1')
			pos++;
		else
		{
			printf("1. Map not surounded by Walls");
			exit (1);
		}		
	}
	if((get_col(map, pos) == 0 || get_col(map, pos) == map->x-1))
	{
		if(map->bitmap[pos] != '1')
		{	
			printf("2. Map not surounded by Walls");
			exit(1);
		}
	}
	return (pos);
}

void add_tokens(t_map *map, size_t pos)
{
	if(map->bitmap[pos] == 'P')
	{	
		set_player_pos(map, pos); //directement envoyer player et pas toute la map
		map->player->amount+=1;
	}	
	if(map->bitmap[pos] == 'C')
		map->coll->amount+=1;	
	if(map->bitmap[pos] == 'E')
	{
		set_exit_pos(map, pos);
		map->exit->amount+=1;
	}
	if (ft_strchr("10PCE" , map->bitmap[pos]) == NULL)
	{
		printf("Not a valid char");
		exit(1);		
	}
	if (map->player->amount > 1 || map->exit->amount > 1)
	{
		printf("Trop de joueur ou de sorties\n");//faire un if par cas pour personnaliser les erreurs
		exit(1);
	}
}



