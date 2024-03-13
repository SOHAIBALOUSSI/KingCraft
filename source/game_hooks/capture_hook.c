
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

static int	game_events(int pressed_key, t_map *game)
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