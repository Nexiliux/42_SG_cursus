CC = cc
CFLAGS += -Wall -Wextra -Werror

SRC = $(SRC_DIR)/ft_printf_helper.c

SRC += ft_printf.c

SRC_DIR = ./src
OBJ_DIR = ./objs
LIBFT_DIR = ./libft

NAME = libftprintf.a
LIB = ar rc
RM = rm -f

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I includes -I libft

all: $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
