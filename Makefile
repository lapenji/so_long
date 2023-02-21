NAME = so_long
SRCS = main.c counters.c errors.c enemy.c img_utils.c map_checker.c free_destroy.c map_generator.c no_events_utils.c map_utils.c movements.c struct_utils.c various_utils.c map_checker2.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS2 = -lXext -lX11 -lm -lz
LIB = minilibx-linux/libmlx.a ft_printf/libftprintf.a

all: mlx ft_printf $(NAME)

bonus : all

%.o: %.c
	$(CC) -c $(CFLAGS) $(SRCS) $(CFLAGS2) $?
mlx:
	cd minilibx-linux && $(MAKE) -s
ft_printf:
	cd ft_printf && $(MAKE) -s
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(CFLAGS2) -o $(NAME)
clean: mlx_clean
	rm -f $(OBJS)
	cd ft_printf && $(MAKE) clean
fclean: clean
	rm -f $(NAME)
	cd ft_printf && $(MAKE) fclean
re: fclean all
mlx_clean:
	cd minilibx-linux/ && $(MAKE) clean
.PHONY: all mlx ft_printf clean fclean re mlx_clean .c.o
