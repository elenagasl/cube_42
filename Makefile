NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC_PATH	= src
BUILD		= build
SRC			= main.c parser.c parse-colors.c parse-map.c parse-map2.c\
			parse-map3.c parser-print.c parse-textures.c trim.c\
			parser-utils.c utils.c validate-file.c validate-map.c
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))
OBJS		= $(addprefix $(BUILD)/, $(SRC:.c=.o))
INCLUDE		= -I./include -I./libft
LDFLAGS		= libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -sC libft libft.a
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(BUILD)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(BUILD)
	$(MAKE) -sC libft clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -sC libft fclean

re : fclean all

debug: CFLAGS = -Wall -Wextra -g3 -O0 -fno-omit-frame-pointer
debug: fclean all

.PHONY : all clean fclean re

#NAME		= cub3D
#CC			= cc
#CFLAGS		= -Wall -Wextra -Werror -I$(MLX_DIR)
#
#MLX_DIR		= ./minilibx
#MLX_LIB		= $(MLX_DIR)/libmlx.a
#
#SRC			= main.c init.c raycasting.c raycasting1.c render.c utils.c map.c exit.c hooks.c draw.c movement2.c movement.c
#OBJ			= $(SRC:.c=.o)
#
#all: $(NAME)
#
#$(NAME): $(OBJ) $(MLX_LIB)
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) \
#		-L$(MLX_DIR) -framework OpenGL -framework AppKit
#
#$(MLX_LIB):
#	$(MAKE) -C $(MLX_DIR)
#
#clean:
#	$(MAKE) -C $(MLX_DIR) clean
#	rm -f $(OBJ)
#
#fclean: clean
#	rm -f $(NAME)
#
#re: fclean all
#
#.PHONY: all clean fclean re
