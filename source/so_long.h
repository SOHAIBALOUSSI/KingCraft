
#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# define RED "\033[0;31m"

typedef struct player
{
	int			x;
	int			y;
	int			colectibles_earned;
	int			is_won;
	int			is_lost;
	int			moves;
}				t_player;

typedef struct map
{
	int			e_count;
	int			p_count;
	int			c_count;
	int			width;
	int			height;
	char		**map_lines;
	char        **map2;
	int			total;
	int         player_x;
	int         player_y;
	int			e_flag;
	void		*ptr;
	void		*win;
	int			display_width;
	int			display_height;
}				t_map;


/*						MAP CHECK						*/
int     validate_map(char *map_path, t_map *map);
void	error_map(char *error_msg, char **map);
void	error(char *error_msg);
char	*read_map(char *map_path, int fd, t_map *map);
int		extension_check(char *map_path);
int		component_check(char **map_lines, t_map *map);
int		not_valid_component(char c);
void	check_result(int flag, t_map *map, char **map_lines);
int	    is_rectangle(char **lines, t_map *map);
int		wall_check(char **map_lines);
void	save_cords_and_count(t_map *map , int x, int y);
void	free_map(char **map);
void 	can_reach_exit(char **map, int start_x, int start_y, t_map *map_data);
int     build_map(t_map *game);
/*					initialization						*/
int 	init_mlx(t_map *mlx);
void    init_structs(t_map *map);



#endif