# NAME = so_long

# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# MLX_DIR = mlx
# MLX_LIB = $(MLX_DIR)/libmlx.a

# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
# INCLUDES = -I$(MLX_DIR)

# SRCS =	main.c \
# 		NAME = so_long

# 		CC = cc
# 		CFLAGS = -Wall -Wextra -Werror

# 		MLX_DIR = mlx
# 		MLX_LIB = $(MLX_DIR)/libmlx.a

# 		MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
# 		INCLUDES = -I$(MLX_DIR)

# 		SRCS = 	main.c \
# 				get_next_line.c \
# 				get_next_line_utils.c \
# 				ft_strncmp.c \
# 				map.c \
# 				ft_split.c \
# 				so_long_utils.c \
# 				map_parsing.c \
# 				path_checker.c \
# 				game_init.c \
# 				render.c \
# 				game_loop.c\
# 				hexa.c\
# 				ft_printf.c\
# 				put.c

# 		OBJS = $(SRCS:.c=.o)

# 		RM = rm -f

# 		all: $(NAME)

# 		$(NAME): $(OBJS)
# 			$(MAKE) -C $(MLX_DIR)
# 			$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

# 		%.o: %.c
# 			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 		clean:
# 			$(RM) $(OBJS)

# 		fclean: clean
# 			$(RM) $(NAME)

# 		re: fclean all

# 		.PHONY: all clean fclean re
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
INCLUDES = -I$(MLX_DIR)

SRCS =  main.c \
        get_next_line.c \
        get_next_line_utils.c \
        ft_strncmp.c \
        map.c \
        ft_split.c \
        so_long_utils.c \
        map_parsing.c \
        path_checker.c \
        game_init.c \
        render.c \
        game_loop.c \
        hexa.c \
        ft_printf.c \
        put.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
