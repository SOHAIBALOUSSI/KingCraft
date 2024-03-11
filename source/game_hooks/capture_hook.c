
#include "../so_long.h"
static int	exit_game(t_map *game)
{
	ft_printf("Closing the window ..\n");
	mlx_destroy_window(game->ptr, game->win);
	mlx_destroy_display(game->ptr);
	free(game->ptr);
	exit(0);
	return (0);
}

static	void move_player_up(t_map *game, int x, int y)
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
				exit(1);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y - 1][x] = 'P';
		game->player_y = y - 1;
		printf("King moves : %d\n",game->player_moves);
		init_map(game);
	}
}

static	void move_player_down(t_map *game, int x, int y)
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
				exit(1);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y + 1][x] = 'P';
		game->player_y = y + 1;
		printf("King moves : %d\n",game->player_moves);
		init_map(game);
	}
}

static	void move_player_right(t_map *game, int x, int y)
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
				exit(1);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y][x + 1] = 'P';
		game->player_x = x + 1;
		printf("King moves : %d\n",game->player_moves);
		init_map(game);
	}
}

static	void	move_player_left(t_map *game, int x , int y)
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
				exit(1);
			}
		}
		game->player_moves++;
		game->map_lines[y][x] = '0';
		game->map_lines[y][x - 1] = 'P';
		game->player_x = x - 1;
		printf("King moves : %d\n",game->player_moves);
		init_map(game);
	}
}

static	void	move_player(t_map *game, char direction)
{
	int x;
	int y;
	
	x = game->player_x;
	y = game->player_y;
	if (direction == UP)
		move_player_up(game, x, y);
	else if (direction == DOWN)
		move_player_down(game, x, y);
	else if (direction == RIGHT)
		move_player_right(game , x, y);
	else if (direction == LEFT)
		move_player_left(game, x, y);
}
static	int	game_events(int pressed_key, t_map *game)
{
	if (pressed_key == 65307)
		exit_game(game);
	else if (pressed_key == W)
		move_player(game ,UP);
	else if (pressed_key == S)
		move_player(game, DOWN);
	else if (pressed_key == D)
		move_player(game ,RIGHT);
	else if (pressed_key == A)
		move_player(game, LEFT);
	
	return (0);
}

void	capture_hook(t_map *game)
{
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, (1L << 0), game_events, game);
}