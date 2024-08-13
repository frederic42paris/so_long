/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:58:01 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 16:47:58 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	is_empty(t_game *game, char *temp, char *concat)
{
	int	i;

	i = 0;
	if (concat[0] == '\0')
	{
		error_message(4);
		free(temp);
		return (1);
	}
	while (concat[i] != '\0')
	{
		if (concat[i] == '\n' && concat[i + 1] == '\n')
		{
			error_message(5);
			free(temp);
			return (1);
		}
		i++;
	}
	game->map = ft_split(concat, '\n');
	free(concat);
	return (0);
}

int	store_map(t_game *game)
{
	char	*string;
	char	*temp;
	char	*concat;

	string = "1";
	concat = ft_strdup("");
	while (string)
	{
		string = NULL;
		temp = concat;
		string = get_next_line(game->fd);
		if (string)
		{
			concat = ft_strjoin(temp, string);
			free(string);
			free(temp);
		}
	}
	if (is_empty(game, temp, concat) == 1)
		return (1);
	return (0);
}
