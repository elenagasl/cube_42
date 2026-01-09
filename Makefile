NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(MLX_DIR)

MLX_DIR		= ./minilibx
MLX_LIB		= $(MLX_DIR)/libmlx.a

SRC			= main.c init.c raycasting.c raycasting1.c render.c utils.c map.c exit.c hooks.c draw.c
OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) \
		-L$(MLX_DIR) -framework OpenGL -framework AppKit

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
