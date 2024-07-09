NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -framework AppKit -framework OpenGL
SRCS =  main.c error.c check_map.c move.c check_map_name.c game_finish.c create_map.c fill_flood.c read_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c

OBJS = $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a

all: $(NAME)

$(MINI):
		make -C ./mlx &> /dev/null

$(NAME): $(MINI) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) -c $^ -o $@ -Wall -Wextra -Werror

clean:
		rm -rf $(OBJS)
		make clean -C mlx/

fclean: clean
		rm -rf $(NAME)
		make clean -C mlx/

re: fclean all

.PHONY: fclean re all clean
