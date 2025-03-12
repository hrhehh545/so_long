CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -lmlx -lXext -lX11 

SRCS = main.c \
       get_next_line/get_next_line.c \
       get_next_line/get_next_line_utils.c \
       map_checker/map_checker.c \
       map_checker/check_characters.c \
       map_checker/helper_f.c \
       map_checker/check_path.c \
       map_checker/check_walls.c \
       map_checker/map_pars.c \
	   mlx/so_long.c \
          mlx/f_help.c  \
          mlx/f2_help.c

OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
