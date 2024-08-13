/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:05:57 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 15:04:07 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	copymap(t_game *game)
{
	int	i;

	i = 0;
	game->map_access = malloc(sizeof(char *) * (game->height));
	if (game->map_access == NULL)
		return ;
	while (i < game->height)
	{
		game->map_access[i] = ft_strdup(game->map[i]);
		i++;
	}
}

void	check_exit(t_game	*game)
{
	int	x;
	int	y;

	x = game->exit_x;
	y = game->exit_y;
	if (game->map_access[y][x + 1] == '2' ||
		game->map_access[y][x - 1] == '2' ||
		game->map_access[y + 1][x] == '2' ||
		game->map_access[y - 1][x] == '2')
		game->map_access[y][x] = '2';
}

void	floodfill(unsigned char x, unsigned char y, t_game *game)
{
	char	**map;

	map = game->map_access;
	if (x <= 0 || x >= (game->height - 1) || y <= 0 || y >= (game->width - 1))
		return ;
	if (map[x][y] == '1' || map[x][y] == '2' || map[x][y] == 'E')
		return ;
	map[x][y] = '2';
	floodfill(x + 1, y, game);
	floodfill(x - 1, y, game);
	floodfill(x, y + 1, game);
	floodfill(x, y - 1, game);
}

int	check_invalid_path(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'C' && game->map_access[j][i] != '2')
			{
				error_message(9);
				return (1);
			}
			else if (game->map[j][i] == 'E' && game->map_access[j][i] != '2')
			{
				error_message(9);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
