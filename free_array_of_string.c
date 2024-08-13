/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_of_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:57:46 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/22 14:14:15 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	free_array_of_string(char **array, int wordnbr)
{
	int	i;

	i = 0;
	while (i < wordnbr)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
