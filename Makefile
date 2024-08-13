SRCS = main.o \
analyse_map.o free_array_of_string.o error_message.o init_mlx_win.o invalid_path.o \
manage_events.o  map_error.o open_file.o put_images.o store_images.o store_map.o wrong_input.o \
./get_next_line/get_next_line.o ./get_next_line/get_next_line_utils.o\

MINILIBX = ~/Desktop/solong/minilibx-linux/libmlx_Linux.a -lXext -lX11

NAME = so_long

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft
	make -C ./printf
	cc -Wall -Wextra -Werror -o $(NAME) $(SRCS) ./printf/libftprintf.a ./libft/libft.a $(MINILIBX)

%.o:%.c 
	cc -Wall -Wextra -Werror -o $@ -c $<

clean:
	make clean -C ./libft
	make clean -C ./printf
	rm -f $(SRCS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

testerleaks:
	valgrind --leak-check=full ./so_long
	valgrind --leak-check=full ./so_long ./maps/map_valid.ber ./maps/map_valid.ber
	valgrind --leak-check=full ./so_long ./maps/map1ber
	valgrind --leak-check=full ./so_long ./maps/map1.bar
	
	valgrind --leak-check=full ./so_long ./maps/map_wrongname.ber

	valgrind --leak-check=full ./so_long ./maps/map_empty.ber
	valgrind --leak-check=full ./so_long ./maps/map_empty_line.ber

	valgrind --leak-check=full ./so_long ./maps/map_unknown_elmt.ber

	valgrind --leak-check=full ./so_long ./maps/map_no_P.ber
	valgrind --leak-check=full ./so_long ./maps/map_no_E.ber
	valgrind --leak-check=full ./so_long ./maps/map_no_C.ber
	valgrind --leak-check=full ./so_long ./maps/map_multiple_E.ber
	valgrind --leak-check=full ./so_long ./maps/map_multiple_P.ber

	valgrind --leak-check=full ./so_long ./maps/map_not_rect.ber

	valgrind --leak-check=full ./so_long ./maps/map_no_wall_left.ber
	valgrind --leak-check=full ./so_long ./maps/map_no_wall_top.ber

	valgrind --leak-check=full ./so_long ./maps/map_invalid_path0.ber
	valgrind --leak-check=full ./so_long ./maps/map_invalid_path1.ber
	valgrind --leak-check=full ./so_long ./maps/map_invalid_path2.ber
	valgrind --leak-check=full ./so_long ./maps/map_invalid_path3.ber
	valgrind --leak-check=full ./so_long ./maps/map_invalid_path4.ber

	valgrind --leak-check=full ./so_long ./maps/map_valid1.ber
	valgrind --leak-check=full ./so_long ./maps/map_valid2.ber

tester:

	./so_long
	./so_long ./maps/map_valid.ber ./maps/map_valid.ber
	./so_long ./maps/map1ber
	./so_long ./maps/map1.bar
	
	./so_long ./maps/map_wrongname.ber

	./so_long ./maps/map_empty.ber
	./so_long ./maps/map_empty_line.ber

	./so_long ./maps/map_unknown_elmt.ber

	./so_long ./maps/map_no_P.ber
	./so_long ./maps/map_no_E.ber
	./so_long ./maps/map_no_C.ber
	./so_long ./maps/map_multiple_E.ber
	./so_long ./maps/map_multiple_P.ber

	./so_long ./maps/map_not_rect.ber

	./so_long ./maps/map_no_wall_left.ber
	./so_long ./maps/map_no_wall_top.ber

	./so_long ./maps/map_invalid_path0.ber
	./so_long ./maps/map_invalid_path1.ber
	./so_long ./maps/map_invalid_path2.ber
	./so_long ./maps/map_invalid_path3.ber
	./so_long ./maps/map_invalid_path4.ber

	./so_long ./maps/map_valid1.ber
	./so_long ./maps/map_valid2.ber