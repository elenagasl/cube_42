NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
UNAME_S		= $(shell uname -s)

SRC			= main.c init.c exit.c utils.c\
				game/draw.c game/hooks.c game/movement.c game/movement2.c\
				game/raycasting.c game/raycasting1.c game/render.c\
				parser/parse-colors.c parser/map-size.c\
				parser/parse-map1.c parser/parse-map2.c parser/parse-player.c\
				parser/map_to_int_arr.c parser/parser.c parser/print-map.c\
				parser/parser-utils.c parser/parse-textures.c parser/trim.c\
				parser/validate-file.c

SRC_PATH	= src
BUILD		= build
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))
OBJS		= $(addprefix $(BUILD)/, $(SRC:.c=.o))

ifeq ($(UNAME_S),Linux)
	MLX_DIR = ./minilibx-linux
	MLX_LIB = $(MLX_DIR)/libmlx.a
	MLX_LDFLAGS = -lm -lXext -lX11
endif

ifeq ($(UNAME_S),Darwin)
	MLX_DIR = ./minilibx
	MLX_LIB = $(MLX_DIR)/libmlx.a
	MLX_LDFLAGS = -framework OpenGL -framework AppKit
endif

INCLUDE		= -I./libft -I$(MLX_DIR)
LDFLAGS		= libft/libft.a $(MLX_LIB) $(MLX_LDFLAGS)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -sC $(MLX_DIR)
	$(MAKE) -sC libft
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(BUILD)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(BUILD)
	$(MAKE) -sC libft clean
	$(MAKE) -sC $(MLX_DIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -sC libft fclean

re : fclean all

debug: CFLAGS = -Wall -Wextra -g3 -O0 -fno-omit-frame-pointer
debug: fclean all

.PHONY : all clean fclean re debug
