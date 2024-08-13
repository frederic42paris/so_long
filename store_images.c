/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:11:42 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/22 18:31:51 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	store_images(t_game *game)
{
	int		img_width;
	int		img_height;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/floor.xpm",
			&img_width, &img_height);
	if (game->floor == NULL)
		return (1);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/cat.xpm",
			&img_width, &img_height);
	if (game->player == NULL)
		return (1);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/wall.xpm",
			&img_width, &img_height);
	if (game->wall == NULL)
		return (1);
	game->item = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/food.xpm",
			&img_width, &img_height);
	if (game->item == NULL)
		return (1);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/house.xpm",
			&img_width, &img_height);
	if (game->exit == NULL)
		return (1);
	return (0);
}
