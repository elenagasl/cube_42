NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRC_PATH	= src
BUILD		= build
SRC			= main.c parser.c parse-colors.c parse-map.c parse-map2.c parse-textures.c trim.c parser-utils.c utils.c validate-file.c validate-map.c
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
