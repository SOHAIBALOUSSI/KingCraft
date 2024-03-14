/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:18:34 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:18:36 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libs/libft/libft.h"

void	can_reach_exit(char **map, int x, int y, t_map *map_data)
{
	if (x < 0 || y < 0 || x >= map_data->width
		|| y >= map_data->height || map[y][x] == '1' )
		return ;
	if (map[y][x] == 'E')
	{
		map_data->e_flag = 1;
		return ;
	}
	if (map[y][x] == 'C')
		map_data->total++;
	map[y][x] = '1';
	can_reach_exit(map, x + 1, y, map_data);
	can_reach_exit(map, x - 1, y, map_data);
	can_reach_exit(map, x, y + 1, map_data);
	can_reach_exit(map, x, y - 1, map_data);
}

int	check_valid_path(char **all_lines, t_map *game)
{
	int	i;

	i = -1;
	game->map__ = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map__)
		return (0);
	while (game->map_lines[++i])
		game->map__[i] = ft_strdup(game->map_lines[i]);
	game->map__[i] = NULL;
	can_reach_exit(game->map__, game->player_x, game->player_y, game);
	if ((game->total == game->c_count && game->e_flag == 1))
	{
		free_map(game->map__);
		return (0);
	}
	else
	{
		free_map(game->map__);
		error_map("There is no valid path to Exit/Collectibles",
			all_lines, game);
	}
	return (0);
}
