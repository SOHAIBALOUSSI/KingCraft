
#include "../so_long.h"
#include "../../Libs/libft/libft.h"

void	error(char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n",RED, error_msg);
	exit(1);
}

// void	error(char *error_msg, char **map)
// {
// 	write(2, "Error\n", 6);
// 	ft_printf("%s%s\n",RED, error_msg);
// 	// free_map(map);
// 	exit(1);
// }

int	not_valid_component(char c)
{
	return (c != 'E' && c != 'P' && c != 'C'&& c != '1' && c != '0');
}

int	check_result(int flag, t_map *map, char **lines)
{	if (flag == 1 && (map->p_count != 1 || map->e_count != 1 || map->c_count < 1))
		error("Invalid map: Unkown compenent and Duplicate/missing elements found!");
	else if (flag == 1)
		error("Invalid Map: Unkown compenent");
	else if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1)
		error("Invalid map: Duplicate or missing elements found!");
	
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

// int main()
// {
// 	error("slm");
// }
