/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:42:55 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/22 18:33:07 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	display_map(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor,
		64 * i, 64 * j);
}

void	display_item(t_game *game, int i, int j)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall,
			64 * i, 64 * j);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->item,
			64 * i, 64 * j);
	else if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit,
			64 * i, 64 * j);
}

void	display_player(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player,
		64 * i, 64 * j);
}

void	put_images(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			display_map(game, i, j);
			display_item(game, i, j);
			display_player(game, game->player_x, game->player_y);
			i++;
		}
		j++;
	}
}
