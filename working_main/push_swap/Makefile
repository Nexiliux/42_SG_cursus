CC = cc
CFLAGS += -Wall -Wextra -Werror
LDFLAGS += -L./libft -L./printf
LIBS += -lft -lftprintf

SRC_DIR = ./src
OBJ_DIR = ./push-swap_objs

SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

all: libft printf $(NAME) $(CLIENT_NAME)

.PHONY: all clean fclean re libft printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c push_swap.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C ./libft

printf:
	$(MAKE) -C ./printf

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./printf clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./printf fclean

re: fclean all