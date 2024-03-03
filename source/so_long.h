
#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../Libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[0;31m"

typedef struct player
{
	int			player_pos_x;
	int			player_pos_y;
	int			colectibles_earned;
	int			is_won;
	int			is_lost;
	int			moves;
}				t_player;

typedef struct map
{
	int			e_count;
	int			p_count;
	int			width;
	int			height;
	char		**map_lines;
	int			c_count;
	t_player	player1;
}				t_map;


/*						MAP CHECK						*/
int    validate_map(char *map_path, t_map *map);
void	error_map(char *error_msg, char **map);
void	error(char *error_msg);
char	*read_map(char *map_path, int fd);
int		extension_check(char *map_path);
int		component_check(char **map_lines, t_map *map);
int		not_valid_component(char c);
int		check_result(int flag, t_map *map, char **map_lines);
int		is_rectangle(char **lines);
int		wall_check(char **map_lines);
void	free_map(char **map);





#endif