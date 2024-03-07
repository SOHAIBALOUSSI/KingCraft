
#include "../so_long.h"
#include "../../libs/libft/libft.h"

void	error(char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n",RED, error_msg);
	exit(1);
}

void	error_map(char *error_msg, char **map)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n",RED, error_msg);
	free_map(map);
	exit(1);
}

void	save_cords_and_count(t_map *map , int x, int y)
{
	map->p_count++;
	map->player_x = x;
	map->player_y = y;
}

int	not_valid_component(char c)
{
	return (c != 'E' && c != 'P' && c != 'C'&& c != '1' && c != '0');
}

void	check_result(int flag, t_map *map, char **lines)
{

	if (flag == 1 && (map->p_count != 1 || map->e_count != 1 || map->c_count < 1))
		error_map("Invalid map: Unkown compenent and Duplicate/missing elements found!", lines);
	else if (flag == 1)
		error_map("Invalid Map: Unkown compenent", lines);
	else if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1)
		error_map("Invalid map: Duplicate or missing elements found!", lines);	
}

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
