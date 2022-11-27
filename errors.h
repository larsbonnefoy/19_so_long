#ifndef ERRORS_H
# define ERRORS_H

# include "so_long.h"
# define FAILURE 1

void	token_error(t_map *map);
void	no_path_error(t_map *map, t_map *map_cpy);
void	wall_error(t_map *map, int x, int y);
void	wrong_char(t_map *map, int x, int y);
void	empty_doc(t_map *map);
void	input_error(int argc, char **argv);
void	line_error(t_map *map, char *str);
void	fd_error(t_map *map);

#endif
