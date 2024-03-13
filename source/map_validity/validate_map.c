/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:18:59 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:19:05 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	validate_map(char *map_path, t_map *map)
{
	int fd;
	char *lines;
	char **all_lines;
	
	lines = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		error("Failed to open, Try an existing file");
	if (extension_check(map_path) == 0)
		error("Failed to open, Not a '.ber' file");
	lines = read_map(fd, map);
	all_lines = ft_split(lines, '\n');
	map->map_lines = all_lines;
	component_check(all_lines, map, lines);
	wall_check(all_lines);
	check_valid_path(map);
	free(lines);
	return (0);
}
