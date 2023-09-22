CC = cc
CFLAGS += -Wall -Wextra -Werror

SRC =

SRC_DIR = ./src
OBJ_DIR = objs
LIBFT_DIR = ./libft

NAME = libftprintf.a
LIB = ar rc
RM = rm -f

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

$(NAME): $(OBJ) $(OBJADD)
	$(LIB) $(NAME) $(OBJ) $(OBJADD)

$(OBJ) = $(OBJ_DIR)%.o: $(SRC_DIR)/%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ -I includes -I libft

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJADD) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all bonus clean fclean re bonus