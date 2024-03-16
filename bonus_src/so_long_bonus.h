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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*			Colors			*/
# define RED "\e[0;31m"
# define GREEN "\e[1;32m"
# define GOLD "\e[38;2;255;215;0m"
# define CLEAR "\e[0;37m"

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
	int			w_count;
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
	t_xpm		*king_right[3];
	t_xpm		*king_left[3];
	t_xpm		*wall;
	t_xpm		*collectible;
	t_xpm		*exit_left[4];
	t_xpm		*exit_right[4];
	t_xpm		*exit_idle_left[2];
	t_xpm		*exit_idle_right[2];
	t_xpm		*enemy[2];
	t_xpm		*king_death[4];
	int			exit_frame;
	int			collectible_frame;
	int			death_frame;
	int			king_frame;
	int			princess_frame;
	int			death_flag;
	int			e_direction;
	int			enemy_reach_left;
	int			enemy_reach_right;
}				t_map;

/*						MAP CHECK						*/
int		validate_map(char *map_path, t_map *map);
void	error_read(char *error_msg, char *lines, char *current);
void	error_map(char *error_msg, char **lines, t_map *map);
void	error(char *error_msg);
char	*read_map(int fd, t_map *map);
int		extension_check(char *map_path);
int		component_check(char **map_lines, t_map *map);
int		not_valid_component(char c, t_map *map);
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

void 	patrolling_enemy(t_map *game);
void	exit_death(t_map *game);

#endif
