/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:18:46 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:18:50 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libs/libft/libft.h"

void	error(char *error_msg)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n", RED, error_msg);
	exit(1);
}

void	error_read(char *error_msg, char *lines, char *current)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n", RED, error_msg);
	free(lines);
	free(current);
	lines = NULL;
	current = NULL;
	exit(1);
}

void	error_map(char *error_msg, char **lines, t_map *map)
{
	write(2, "Error\n", 6);
	ft_printf("%s%s\n", RED, error_msg);
	free_map(lines);
	free(map->validate_line);
	map->validate_line = NULL;
	exit(1);
}

void	check_result(int flag, t_map *map, char **lines)
{
	if (flag == 1 && (map->p_count != 1 || map->e_count != 1
			|| map->c_count < 1))
		error_map("Unkown compenent & Duplicate/missing elements found!",
			lines, map);
	else if (flag == 1)
		error_map("Invalid Map: Unkown compenent", lines, map);
	else if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1)
		error_map("Duplicate/missing elements found!", lines, map);
}
