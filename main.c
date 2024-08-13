/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:17 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 16:53:08 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

// void	printarray(t_game *game, char **array)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	printf("Resulting Screen:\n");
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (j < game->width)
// 		{
// 			printf("%c ", array[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

int	map_error(t_game *game)
{
	int	invalid_path;

	invalid_path = 0;
	if (elements_missing(game) == 1)
		return (1);
	if (unknown_element(game) == 1)
		return (1);
	if (not_rectangular(game) == 1)
		return (1);
	if (no_walls(game) == 1)
		return (1);
	copymap(game);
	floodfill(game->player_y, game->player_x, game);
	check_exit(game);
	invalid_path = check_invalid_path(game);
	free_array_of_string(game->map_access, game->height);
	if (invalid_path == 1)
		return (1);
	return (0);
}

int	so_long(t_game	*game, int argc, char **argv)
{
	if (wrong_input(argv[1], argc) == 1)
		return (0);
	if (game == NULL)
		return (0);
	if (open_file(game, argv[1]) == 1)
		return (0);
	if (store_map(game) == 1)
		return (0);
	analyse_map(game);
	if (map_error(game) == 1)
		return (0);
	if (init_mlx_win(game) == 1)
		return (0);
	if (store_images(game) == 1)
		return (0);
	put_images(game);
	manage_events(game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->map = NULL;
	so_long(game, argc, argv);
	if (game->map)
		free_array_of_string(game->map, game->height);
	free(game);
}
