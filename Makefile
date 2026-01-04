NAME		= parser-exe
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g3
SRC_PATH	= parser
BUILD		= build
SRC			= main.c files.c file-validation.c line-validation.c trim.c colors.c textures.c utils.c
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

.PHONY : all clean fclean re
