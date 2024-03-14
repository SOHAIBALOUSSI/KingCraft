/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:17:48 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/07 21:17:50 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../../libs/libft/libft.h"

int	init_mlx(t_map *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (1);
	mlx->win = mlx_new_window(mlx->ptr,
			mlx->width * 60, mlx->height * 60, "batman");
	if (!mlx->win)
		return (free(mlx->ptr), 1);
	return (1);
}
