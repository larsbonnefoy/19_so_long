#include "errors.h"

void	empty_doc(t_map *map)
{
	ft_printf("Error\nEmpty doc\n");
	free_map(map);
	exit(FAILURE);
}

void	input_error(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of argumets provided\n");
		exit(FAILURE);
	}	
	len = (int)ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
	{
		ft_printf("Error\nNot a .ber map file\n");
		exit(FAILURE);
	}
}

void	fd_error(t_map *map)
{
	ft_printf("Error\nCould not open file");
	free_map(map);
	exit(FAILURE);
}
