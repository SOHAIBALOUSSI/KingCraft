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

#include "so_long_bonus.h"

static	void	get_screen_size(t_map *game)
{
	game->ptr = mlx_init();
	mlx_get_screen_size(game->ptr, &game->display_width,
		&game->display_height);
	mlx_destroy_display(game->ptr);
	free(game->ptr);
}

static	int	fps(t_map *game)
{
	static int	enemy_wait = 1;
	static int	exit_wait = 1;

	game->king_frame = 0;
	if (game->c_count == game->collected && game->exit_frame < 4)
		game->exit_frame++;
	if (game->death_flag == 1)
	{
		if (game->death_frame < 3)
			game->death_frame++;
		if (exit_wait % 10 == 0)
			exit_game(game);
		exit_wait++;
	}
	if (enemy_wait % 5 == 0)
		patrolling_enemy(game);
	enemy_wait++;
	game->princess_frame = (game->princess_frame + 1) % 2;
	init_map(game);
	game->king_frame = (game->king_frame + 1) % 2;
	usleep(100000);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error("Use : ./so_long <path_to_map>.ber");
	map = (t_map){0};
	get_screen_size(&map);
	validate_map(av[1], &map);
	init_mlx(&map);
	init_xpm(&map);
	system("cvlc ./assets/so_long.mp3 &");
	capture_hook(&map);
	mlx_loop_hook(map.ptr, &fps, &map);
	mlx_loop(map.ptr);
	return (0);
}
