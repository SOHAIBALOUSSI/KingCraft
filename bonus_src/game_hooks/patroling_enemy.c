#include "../so_long_bonus.h"

#include <time.h>


static int	can_move(t_map *game, int x, int y)
{
	return (game->map_lines[y][x] == '0'|| game->map_lines[y][x] == 'P');
}

static void	move_left(t_map *game, int *x, int y)
{
	if (game->map_lines[y][(*x) - 1] == 'P')
	{
		game->death_flag = 1;
		return ;
	}
	game->map_lines[y][*x] = '0';
	game->map_lines[y][*x - 1] = 'W';
}

static void	move_right(t_map *game, int *x, int y)
{
	if (game->map_lines[y][(*x) + 1] == 'P')
	{
		game->death_flag = 1;
		return ;
	}
	game->map_lines[y][*x] = '0';
	game->map_lines[y][(*x) + 1] = 'W';
}

void	update_monster_position(t_map *game, int *x, int y)
{
	if (can_move(game, (*x) - 1, y) && !game->enemy_reach_left)
	{
		move_left(game, x, y);
		if (!can_move(game, (*x) - 2, y))
		{
			game->enemy_reach_left = 1;
			game->enemy_reach_right = 0;
		}
		return ;
	}
	if (can_move(game, (*x) + 1, y) && !game->enemy_reach_right)
	{
		move_right(game, x, y);
		if (!can_move(game, (*x) + 2, y))
		{
			game->enemy_reach_right = 1;
			game->enemy_reach_left = 0;
		}
		(*x)++;
		return ;
	}
}

void	patrolling_enemy(t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_lines[y])
	{
		x = 0;
		while (game->map_lines[y][x])
		{
			if (game->map_lines[y][x] == 'W')
				update_monster_position(game, &x, y);
			x++;
		}
		y++;
	}
}
