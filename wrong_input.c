/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:35:18 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 13:16:42 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	wrong_input(char *filename, int inputnumber)
{
	char	*string;

	if (inputnumber != 2)
	{
		error_message(1);
		return (1);
	}
	string = ft_strrchr(filename, '.');
	if (string == 0)
	{
		error_message(2);
		return (1);
	}
	if (ft_strncmp(string, ".ber", 4) != 0)
	{
		error_message(2);
		return (1);
	}
	return (0);
}
