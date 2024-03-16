#include "../so_long.h"

static	void	destroy_xpm(t_map *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(game->ptr, game->king[i]->xpm_data);
		mlx_destroy_image(game->ptr, game->princess_exit[i++]->xpm_data);
	}
	mlx_destroy_image(game->ptr, game->bg->xpm_data);
	mlx_destroy_image(game->ptr, game->wall->xpm_data);
	mlx_destroy_image(game->ptr, game->collectible->xpm_data);
}

static	void	free_xpm(t_map *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		free(game->princess_exit[i]);
		free(game->king[i]);
	}
	free(game->wall);
	free(game->bg);
	free(game->collectible);
}

int	exit_game(t_map *game)
{
	free_map(game->map_lines);
	destroy_xpm(game);
	free_xpm(game);
	mlx_destroy_window(game->ptr, game->win);
	mlx_destroy_display(game->ptr);
	free(game->ptr);
	exit(0);
	return (0);
}

void	exit_won(t_map *game)
{
	ft_printf("%sYou won! The princess is free.%s\n", GREEN, CLEAR);
	exit_game(game);
}

void	print_moves(t_map *game)
{
	game->player_moves++;
	ft_printf("King moves : %s%d%s\n", GOLD, 
		game->player_moves, CLEAR);
}