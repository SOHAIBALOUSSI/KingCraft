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

#include "../so_long_bonus.h"

static	t_xpm	*create_image(t_map	*mlx, char *path)
{
	t_xpm	*asset;

	asset = malloc(sizeof(t_xpm));
	if (!asset)
		return (NULL);
	*asset = (t_xpm){0};
	asset->path = path;
	asset->xpm_data = mlx_xpm_file_to_image(mlx->ptr, asset->path,
			&asset->width, &asset->height);
	return (asset);
}

static	void	king_xpm(t_map *game)
{
	game->king_right[0] = create_image(game, "./assets/king-right.xpm");
	game->king_right[1] = create_image(game, "./assets/king-idle-right.xpm");
	game->king_right[2] = create_image(game, "./assets/king-heart-right.xpm");
	
	game->king_left[0] = create_image(game, "./assets/king-left.xpm");
	game->king_left[1] = create_image(game, "./assets/king-idle-left.xpm");
	game->king_left[2] = create_image(game, "./assets/king-heart-left.xpm");
	

	game->king_death[0] = create_image(game, "./assets/death-0.xpm");
	game->king_death[1] = create_image(game, "./assets/death-1.xpm");
	game->king_death[2] = create_image(game, "./assets/death-2.xpm");
	game->king_death[3] = create_image(game, "./assets/death-3.xpm");
}

static	void	princess_exit_xpm(t_map *game)
{

	game->exit_left[0] = create_image(game, "./assets/EXIT-LEFT-0.xpm");
	game->exit_left[1] = create_image(game, "./assets/EXIT-LEFT-1.xpm");
	game->exit_left[2] = create_image(game, "./assets/EXIT-LEFT-2.xpm");
	game->exit_left[3] = create_image(game, "./assets/EXIT-LEFT-3.xpm");
	game->exit_idle_left[0] = create_image(game, "./assets/princess-left.xpm");
	game->exit_idle_left[1] = create_image(game, "./assets/princess-idle-left.xpm");

	game->exit_right[0] = create_image(game, "./assets/EXIT-RIGHT-0.xpm");
	game->exit_right[1] = create_image(game, "./assets/EXIT-RIGHT-1.xpm");
	game->exit_right[2] = create_image(game, "./assets/EXIT-RIGHT-2.xpm");
	game->exit_right[3] = create_image(game, "./assets/EXIT-RIGHT-3.xpm");
	game->exit_idle_right[0] = create_image(game, "./assets/princess-right.xpm");
	game->exit_idle_right[1] = create_image(game, "./assets/princess-idle-right.xpm");

}
void	init_xpm(t_map *game)
{
	king_xpm(game);
	princess_exit_xpm(game);

	game->enemy[0] = create_image(game, "./assets/enemy-left.xpm");
	game->enemy[1] = create_image(game, "./assets/enemy-right.xpm");
	game->bg = create_image(game, "./assets/bg.xpm");
	game->wall = create_image(game, "./assets/wall.xpm");
	game->collectible = create_image(game, "./assets/c1.xpm");
}
