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
	asset->xpm_data = mlx_xpm_file_to_image(mlx->ptr,
			asset->path, &asset->width, &asset->height);
	return (asset);
}

static void	init_player_exit_xpm(t_map *game)
{
	game->king = create_image(game, "assets/king.xpm");
	game->princess_exit[0] = create_image(game, "assets/princess_exit.xpm");
}

static void	init_game_xpm(t_map *game)
{
	game->bg = create_image(game, "assets/bg.xpm");
	game->wall = create_image(game, "assets/tree.xpm");

}
void	init_xpm(t_map *game)
{
	init_player_xpm(game);
	init_game_xpm(game);
}