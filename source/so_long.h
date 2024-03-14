/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:19:15 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:19:27 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*	Colors	*/
# define RED "\033[0;31m"

/* Keysyms from : keysymdef.h */
# define ESC 0xff1b
# define W 0x0077
# define S 0x0073
# define A 0x0061
# define D 0x0064

# define UP 'u'
# define DOWN 'd'
# define LEFT 'l'
# define RIGHT 'r'

typedef struct xpm
{
	int			width;
	int			height;
	int			x;
	int			y;
	char		*path;
	void		*xpm_data;
}				t_xpm;

typedef struct map
{
	int			e_count;
	int			p_count;
	int			c_count;
	int			e_flag;
	int			width;
	int			height;
	int			display_width;
	int			display_height;
	int			collected;
	int			view_;
	char		**map_lines;
	char		**map__;
	char		*validate_line;
	int			total;
	int			player_x;
	int			player_y;
	int			player_moves;
	void		*ptr;
	void		*win;
	t_xpm		*bg;
	t_xpm		*king[4];
	t_xpm		*wall;
	t_xpm		*collectible;
	t_xpm		*princess_exit[4];

}				t_map;

/*						MAP CHECK						*/
int		validate_map(char *map_path, t_map *map);
void	error_read(char *error_msg, char *lines, char *current);
void	error_map(char *error_msg, char **lines, t_map *map);
void	error(char *error_msg);
char	*read_map(int fd, t_map *map);
int		extension_check(char *map_path);
int		component_check(char **map_lines, t_map *map);
int		not_valid_component(char c);
void	check_result(int flag, t_map *map, char **lines);
int		wall_check(char **map_lines, t_map *map);
void	save_cords_and_count(t_map *map, int x, int y);
void	free_map(char **map);
void	can_reach_exit(char **map, int start_x, int start_y, t_map *map_data);
int		check_valid_path(char **all_lines, t_map *game);
/*					Initialization						*/
int		init_mlx(t_map *mlx);
void	init_xpm(t_map *game);
void	init_map(t_map *game);

void	capture_hook(t_map *game);
void	move_player(t_map *game, char direction);
int		exit_game(t_map *game);

#endif
