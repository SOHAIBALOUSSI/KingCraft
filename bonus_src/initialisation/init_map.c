/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:17:36 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:17:40 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	int	push_image(t_map *game, t_xpm *image, int x, int y)
{
	image->x = x * 60;
	image->y = y * 60;
	return (mlx_put_image_to_window(game->ptr, game->win, image->xpm_data,
			image->x, image->y));
}

static	void	push_player_image(t_map *game, int x, int y)
{
	if (game->view_ == 0)
	{
		if (game->map_lines[y][x + 1] == 'E' &&
			(game->collected == game->c_count))
			push_image(game, game->king[2], x, y);
		else
			push_image(game, game->king[0], x, y);
	}
	else
	{
		if (game->map_lines[y][x - 1] == 'E' &&
			(game->collected == game->c_count))
			push_image(game, game->king[3], x, y);
		else
			push_image(game, game->king[1], x, y);
	}
}

static	void	push_exit_image(t_map *game, int x, int y)
{
	if ((game->map_lines[y][x + 1] == '1') || game->player_x <= x)
	{
		if (game->c_count == game->collected)
			push_image(game, game->exit[0], x, y);
		else
			push_image(game, game->exit[1], x, y);
	}
	else
	{
		if (game->c_count == game->collected)
			push_image(game, game->exit[2], x, y);
		else
			push_image(game, game->exit[3], x, y);
	}
}

static	void	check_element_and_push(t_map *game, int x, int y, char element)
{
	if (element == '0')
		push_image(game, game->bg, x, y);
	else if (element == '1')
		push_image(game, game->wall, x, y);
	else if (element == 'C')
		push_image(game, game->collectible, x, y);
	else if (element == 'E')
		push_exit_image(game, x, y);
	else if (element == 'P')
		push_player_image(game, x, y);
	else if (element == 'W')
		push_image(game, game->enemy[0], x, y);
}

void	init_map(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_lines[y])
	{
		x = 0;
		while (game->map_lines[y][x])
		{
			check_element_and_push(game, x, y, game->map_lines[y][x]);
			x++;
		}
		y++;
	}
}
