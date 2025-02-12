CC = cc
CFLAGS = #-Wall -Wextra -Werror
MLX_PATH = /usr/local/lib/minilibx-linux/
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
SRCS = main.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       map_checker/map_checker.c \
       map_checker/check_characters.c \
	   map_checker/helper_f.c \
	   map_checker/check_path.c \
	   map_checker/check_walls.c \
	   mlx/print_map.c 
OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
