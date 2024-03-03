/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:00:56 by sait-alo          #+#    #+#             */
/*   Updated: 2024/02/28 22:01:03 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	extension_check(char *map_path)
{
	char	*extention;

	if (!map_path)
		return (0);
	extention = ft_strrchr(map_path, '.');
	if (!extention)
		return (0);
	if (ft_strlen(extention) != 4)
			return (0);
	if (ft_strncmp(extention, ".ber", 4) == 0 )
		return (1);
	return (0);
}

char	*read_map(char *map_path, int fd)
{
	char	*current_line = NULL;
	char	*full_line = NULL;

	while (1)
	{
		current_line = get_next_line(fd);
		if (!current_line)
			break ;
		full_line = ft_strjoin(full_line, current_line);
		free(current_line);
	}
	if (!full_line)
		return (NULL);
	return (full_line);
}

int	is_rectangle(char **lines)
{
	int	y;
	int	firstlength;

	if (!*lines)
		error("Invalid Map!");
	y = 0;
	firstlength = ft_strlen(lines[0]);
	while (lines[y])
	{
		if (ft_strlen(lines[y]) != firstlength)
			error("Invalid Map: Map is not rectangular!");
		y++;
	}
	return (0);
}

/* Function to check if the map has only one player, one exit,
and at least one collectible */
int	component_check(char **map_lines, t_map *map)
{
	int	x;
	int	y;
	int flag;

	y = 0;
	flag = 0;
	while (map_lines[y])
	{
		x = 0;
		while (map_lines[y][x])
		{
			if (map_lines[y][x] == 'P')
				map->p_count++;
			else if (map_lines[y][x] == 'E')
				map->e_count++;
			else if (map_lines[y][x] == 'C')
				map->c_count++;
			else if (not_valid_component(map_lines[y][x]))
				flag = 1;
			x++;
		}
		y++;
	}
	check_result(flag, map, map_lines);
	return (0);
}

int	wall_check(char **map_lines)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = 0;
	while (map_lines[y])
	{
		len = ft_strlen(map_lines[y]);
		if (len < 3 || map_lines[y][0] != '1' || map_lines[y][len - 1] != '1')
			error("Invalid map : The map is missing walls around its edges");
		if (y == 0 || map_lines[y + 1] == NULL)
		{
			x = 0;
			while (map_lines[y][x])
			{
				if (map_lines[y][x] != '1')
					error("Invalid map : The map is missing top or down walls");
				x++;
			}
		}
		y++;
	}
	return (0);
}
// int main()
// {
// 	t_map test;
// 	test.c_count = 0;
// 	test.e_count = 0;
// 	test.p_count = 0;

// 	char **map;
// 	map = ft_split("11111\n11C111\n1P111\n11111\n11E11", '\n');
// 	int res = ex(map, &test);
// 	if (!res)
// 		ft_printf("valid");

// 	extension_check("")

// 	// int i = 0;
// 	// while (map[i])
// 	// 	ft_printf("%s \n", map[i++]);
	
// }

// int main()
// {
//     extension_check("map.bea");
// }