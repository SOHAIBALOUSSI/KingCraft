/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:27:43 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/12 08:27:49 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/so_long.h"

static	void	get_screen_size(t_map *game)
{
	game->ptr = mlx_init();
	mlx_get_screen_size(game->ptr , &game->display_width ,&game->display_height);
	mlx_destroy_display(game->ptr);
	free(game->ptr);
}

int	main(int ac, char **av)
{
	t_map map;

	if (ac != 2)
		error("Use : ./so_long <path_to_map>.ber");
	map = (t_map){0};
	get_screen_size(&map);
	validate_map(av[1], &map);
	init_mlx(&map);
	init_xpm(&map);
	init_map(&map);
	capture_hook(&map);
	mlx_loop(map.ptr);
}
