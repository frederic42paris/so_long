/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:18:41 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 13:29:08 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	open_file(t_game	*game, char *string)
{
	game->fd = open(string, O_RDONLY);
	if (game->fd < 0)
	{
		error_message(3);
		return (1);
	}
	return (0);
}
