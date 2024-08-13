/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:51:25 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 16:57:20 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	elements_missing(t_game *game)
{
	if (game->hasexit != 1 || game->total_items == 0 || game->hasplayer != 1)
	{
		error_message(6);
		return (1);
	}
	else
		return (0);
}

int	not_rectangular(t_game *game)
{
	int		i;
	int		j;
	int		temp;

	temp = 0;
	while (game->map[0][temp] != '\0')
		temp++;
	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
			i++;
		if (i != temp)
		{
			error_message(7);
			return (1);
		}
		j++;
	}
	return (0);
}

int	no_walls(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][game->width - 1] != '1')
		{
			error_message(8);
			return (1);
		}
		j++;
	}
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			error_message(8);
			return (1);
		}
		i++;
	}
	return (0);
}

int	unknown_element(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] != '0' && game->map[j][i] != '1'
				&& game->map[j][i] != 'P' && game->map[j][i] != 'E' &&
				game->map[j][i] != 'C')
			{
				error_message(10);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
