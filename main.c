
#include "source/so_long.h"

static	void	get_screen_size(t_map *game)
{
	game->ptr = mlx_init();
	mlx_get_screen_size(game->ptr , &game->display_width ,&game->display_height);
	// ft_printf("%d - %d\n", game->display_height, game->display_width);
	free(game->ptr);
}

int main(int ac, char **av)
{
	t_map map;

	if (ac != 2)
		error("Use : ./so_long <path_to_map>.ber");
	init_structs(&map);
	get_screen_size(&map);
	validate_map(av[1], &map);
	init_mlx(&map);
	init_xpm(&map);
	init_map(&map);

	mlx_loop(map.ptr);
}
