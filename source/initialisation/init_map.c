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

#include "../so_long.h"

// void	push_player_image(t_map *game, t_xpm *image, int x, int y)
// {

// }
static	int push_image(t_map *game, t_xpm *image, int x, int y)
{

	image->x = x * 60;
	image->y = y * 60;
	return (mlx_put_image_to_window(game->ptr, game->win, image->xpm_data,
		image->x, image->y));
}

static	void	push_image_exit(t_map *game ,int x, int y)
{
	if ((game->map_lines[y][x + 1] == '1') || game->player_x <= x)
	{
		if (game->c_count == game->collected)
			push_image(game, game->princess_exit[0], x, y); // left
		else
			push_image(game, game->princess_exit[1], x, y);
	}
	else
	{
		if (game->c_count == game->collected)
			push_image(game, game->princess_exit[2], x, y); // right
		else
			push_image(game, game->princess_exit[3], x, y);
	}
}
void	check_element_and_push(t_map *game, int x, int y, char element)
{
	if (element == '0')
		push_image(game, game->bg, x, y);
	else if (element == '1')
		push_image(game, game->wall, x, y);
	else if (element == 'C')
		push_image(game , game->collectible, x, y);
	else if (element == 'E')
		push_image_exit(game, x, y);
	else if (element == 'P')
	{	
		if (game->view_ == 1)
			push_image(game, game->king[1], x, y);
		else
			push_image(game, game->king[0], x, y);
	}
}
void	init_map(t_map  *game)
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