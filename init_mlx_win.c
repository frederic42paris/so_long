/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:52:50 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/22 18:30:39 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	init_mlx_win(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->width * 64, game->height * 64, "so_long");
	if (game->win_ptr == NULL)
		return (1);
	return (0);
}
