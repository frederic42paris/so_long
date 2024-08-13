/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:42:59 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 16:57:49 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	count_items(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'C')
		game->total_items++;
}

void	find_player(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'P')
	{
		game->player_x = i;
		game->player_y = j;
		game->hasplayer++;
	}
}

void	has_exit(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		game->exit_x = i;
		game->exit_y = j;
		game->hasexit++;
	}
}

void	measure_map(t_game *game, int i, int j)
{
	game->width = i;
	game->height = j;
}

void	analyse_map(t_game *game)
{
	int		i;
	int		j;

	game->movements = 0;
	game->total_items = 0;
	game->hasexit = 0;
	game->hasplayer = 0;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			count_items(game, i, j);
			find_player(game, i, j);
			has_exit(game, i, j);
			i++;
		}
		j++;
	}
	measure_map(game, i, j);
}
