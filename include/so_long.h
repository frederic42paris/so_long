/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:36:33 by ftanon            #+#    #+#             */
/*   Updated: 2024/03/24 16:54:38 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/ftanon/Desktop/solong/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"

typedef struct s_game
{
	char			**map;
	char			**map_access;
	int				fd;
	int				width;
	int				height;
	unsigned int	player_x;
	unsigned int	player_y;
	unsigned int	exit_x;
	unsigned int	exit_y;
	int				total_items;
	int				hasexit;
	int				hasplayer;	
	int				movements;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*floor;
	void			*player;
	void			*wall;
	void			*item;
	void			*exit;
}	t_game;

// 1. check_argument_input
int		wrong_input(char *filename, int inputnumber);

// 2. open_file
int		open_file(t_game	*game, char *string);

// 2. store_map
int		store_map(t_game *game);

// 3. analyse_map
void	analyse_map(t_game *game);

// 4. initialize_game
int		init_mlx_win(t_game *game);

// 5. store_images
int		store_images(t_game *game);

// 6. display_elements
void	put_images(t_game *game);

// 7. check_valid_path
int		check_invalid_path(t_game *game);
void	floodfill(unsigned char x, unsigned char y, t_game *game);
void	check_exit(t_game	*game);
void	copymap(t_game *game);

// 8. check_map_errors
int		no_walls(t_game *game);
int		not_rectangular(t_game *game);
int		elements_missing(t_game *game);
int		unknown_element(t_game *game);

// 9. error_message
void	error_message(int num);

// 10. events
int		on_keypress(int keysym, t_game *game);
int		destroy(t_game *game);
void	manage_events(t_game *game);

// free_array_of_strings
int		free_array_of_string(char **array, int wordnbr);

#endif