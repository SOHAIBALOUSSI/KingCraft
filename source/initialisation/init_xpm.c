/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:18:10 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:18:13 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	t_xpm	*create_image(t_map	*mlx, char *path)
{
	t_xpm	*asset;

	asset = malloc(sizeof(t_xpm));
	if (!asset)
		return (NULL);
	asset->path = path;
	asset->height = 0;
	asset->width = 0;
	asset->x = 0;
	asset->y = 0;
	asset->xpm_data = mlx_xpm_file_to_image(mlx->ptr, asset->path, &asset->width, &asset->height);
	return (asset);
}

static void	init_player_exit_xpm(t_map *game)
{
	game->king[0] = create_image(game, "./assets/king-right.xpm");
	game->king[1] = create_image(game, "assets/king-left.xpm");
	game->princess_exit[0] = create_image(game, "./assets/princess-left.xpm");
	game->princess_exit[1] = create_image(game, "assets/closed-prison-left.xpm");
	game->princess_exit[2] = create_image(game, "assets/princess-right.xpm");
	game->princess_exit[3] = create_image(game, "assets/closed-prison-right.xpm");
}

static void	init_game_xpm(t_map *game)
{
	game->bg = create_image(game, "./assets/bg.xpm");
	game->wall = create_image(game, "./assets/wall.xpm");
	game->collectible = create_image(game, "./assets/c1.xpm");
}
void	init_xpm(t_map *game)
{
	init_player_exit_xpm(game);
	init_game_xpm(game);
}
