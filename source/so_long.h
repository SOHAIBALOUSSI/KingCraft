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

#include "../mlx/mlx.h"
#include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
# define RED "\033[0;31m"

# define W 119
# define S 115
# define A 97
# define D 100

# define UP 'u'
# define DOWN 'd'
# define LEFT 'l'
# define RIGHT 'r'

typedef struct	xpm
{
	int			width;
	int			height;
	int			x;
	int			y;
	char		*path;
	void		*xpm_data;
}				t_xpm;

typedef struct	map
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
	char		**map_lines;
	char		**map__;
	int			total;
	int			player_x;
	int			player_y;
	int			player_moves;
	void		*ptr;
	void		*win;
	t_xpm	*bg;
	t_xpm	*king[2];
	t_xpm	*wall;
	t_xpm	*collectible;
	t_xpm	*princess_exit[4];



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
void	init_xpm(t_map *game);
void	init_map(t_map  *game);

void	capture_hook(t_map *game);


#endif
