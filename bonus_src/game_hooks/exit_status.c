/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:48:35 by sait-alo          #+#    #+#             */
/*   Updated: 2024/03/17 18:48:37 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_won(t_map *game)
{
	ft_printf("%sYou won! The princess is free.%s\n", GREEN, CLEAR);
	exit_game(game);
}
