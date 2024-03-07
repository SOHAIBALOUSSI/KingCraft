#include "../so_long.h"
#include "../../libs/libft/libft.h"

void	can_reach_exit(char **map, int x, int y, t_map *map_data)
{
	if (x < 0 || y < 0 || x >= map_data->width || y >= map_data->height || map[y][x] == '1' )
		return ;
	if(map[y][x] == 'E')
	{
		map_data->e_flag = 1;
		return ;
	}
	if ( map[y][x] == 'C')
		map_data->total++;
    map[y][x] = '1';
    can_reach_exit(map, x + 1, y, map_data);
    can_reach_exit(map, x - 1, y, map_data);
    can_reach_exit(map, x, y + 1, map_data);
    can_reach_exit(map, x, y - 1, map_data); 

} 

int	build_map(t_map *game)
{
	int		i;
	char	**tmp_map;
	int		*counter;

	i = -1;
	tmp_map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (tmp_map == NULL)
		return (0);
	counter = 0;
	while (game->map_lines[++i])
		tmp_map[i] = ft_strdup(game->map_lines[i]);
	tmp_map[i] = NULL;
	can_reach_exit(tmp_map, game->player_x, game->player_y, game);
	if ((game->total == game->c_count && game->e_flag == 1))
		return 0;
	else
		error("There is no valid path to Exit/Collectibles");
}
