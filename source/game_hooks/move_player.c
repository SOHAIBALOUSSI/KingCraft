/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:44:49 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/13 15:44:52 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	move_player_up(t_map *game, int x, int y)
{
	if (game->map_lines[y - 1][x] != '1')
	{
		if (game->map_lines[y - 1][x] == 'C')
			game->collected++;
		else if (game->map_lines[y - 1][x] == 'E')
		{
			if (game->collected != game->c_count)
			{
				printf("Colllect all the Hearts to save the Princess\n");
				return ;
			}
			else
			{
				printf("You won!");
				exit_game(game);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y - 1][x] = 'P';
		game->player_y = y - 1;
		ft_printf("King moves : %d\n", game->player_moves);
		init_map(game);
	}
}

static	void	move_player_down(t_map *game, int x, int y)
{
	if (game->map_lines[y + 1][x] != '1')
	{
		if (game->map_lines[y + 1][x] == 'C')
			game->collected++;
		else if (game->map_lines[y + 1][x] == 'E')
		{
			if (game->collected != game->c_count)
			{
				printf("Colllect all the Hearts to save the Princess\n");
				return ;
			}
			else
			{
				printf("You won!");
				exit_game(game);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y + 1][x] = 'P';
		game->player_y = y + 1;
		ft_printf("King moves : %d\n", game->player_moves);
		init_map(game);
	}
}

static	void	move_player_right(t_map *game, int x, int y)
{
	game->view_ = 0;
	if (game->map_lines[y][x + 1] != '1')
	{
		if (game->map_lines[y][x + 1] == 'C')
			game->collected++;
		else if (game->map_lines[y][x + 1] == 'E')
		{
			if (game->collected != game->c_count)
			{
				printf("Colllect all the Hearts to save the Princess\n");
				return ;
			}
			else
			{
				printf("You won!");
				exit_game(game);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y][x + 1] = 'P';
		game->player_x = x + 1;
		ft_printf("King moves : %d\n", game->player_moves);
		init_map(game);
	}
}

static	void	move_player_left(t_map *game, int x, int y)
{
	game->view_ = 1;
	if (game->map_lines[y][x - 1] != '1')
	{
		if (game->map_lines[y][x - 1] == 'C')
			game->collected++;
		else if (game->map_lines[y][x - 1] == 'E')
		{
			if (game->collected != game->c_count)
			{
				printf("Colllect all the Hearts to save the Princess\n");
				return ;
			}
			else
			{
				printf("You won!");
				exit_game(game);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y][x - 1] = 'P';
		game->player_x = x - 1;
		ft_printf("King moves : %d\n", game->player_moves);
		init_map(game);
	}
}

void	move_player(t_map *game, char direction)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (direction == UP)
		move_player_up(game, x, y);
	else if (direction == DOWN)
		move_player_down(game, x, y);
	else if (direction == RIGHT)
		move_player_right(game, x, y);
	else if (direction == LEFT)
		move_player_left(game, x, y);
}
