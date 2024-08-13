/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:45:38 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 14:58:11 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->player);
	mlx_destroy_image(game->mlx_ptr, game->wall);
	mlx_destroy_image(game->mlx_ptr, game->item);
	mlx_destroy_image(game->mlx_ptr, game->exit);
	mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_array_of_string(game->map, game->height);
	free(game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

void	requested_move(int *x, int *y, int keysym)
{
	if (keysym == 100)
		(*x)++;
	else if (keysym == 115)
		(*y)++;
	else if (keysym == 97)
		(*x)--;
	else if (keysym == 119)
		(*y)--;
}

void	move(int keysym, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	requested_move(&x, &y, keysym);
	if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == 'C')
		game->total_items--;
	else if (game->map[y][x] == 'E' && game->total_items > 0)
		return ;
	else if (game->map[y][x] == 'E' && game->total_items == 0)
		destroy(game);
	game->map[game->player_y][game->player_x] = '0';
	game->map[y][x] = 'P';
	game->movements++;
	ft_printf("Number of movements : %d\n", game->movements);
	game->player_x = x;
	game->player_y = y;
	put_images(game);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
		destroy(game);
	else if (keysym == 100 || keysym == 115 || keysym == 97 || keysym == 119)
		move(keysym, game);
	else
		return (0);
	return (0);
}

void	manage_events(t_game *game)
{
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &destroy, game);
}
