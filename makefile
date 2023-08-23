NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a

SRCS = so_long.c \
		read_and_isvalid_map_check.c\
		check_file.c\
		get_img.c\
		render_map.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		what_key.c\
		seach_error.c\
		link_line.c\
		put_msg.c\
		search_goal.c\
		init_game.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_PATH)/libftprintf.a

MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a

all:	$(LIBFT) $(FT_PRINTF_LIB) $(MLX_LIB) $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_PATH)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF_LIB) $(MLX_LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re