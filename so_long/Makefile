CC = cc
CFLAGS += -Wall -Werror -Wextra
LDFLAGS += -L./libft -L./printf
LIBS += -lft -lftprintf

SRC_DIR = ./src
OBJ_DIR = ./so-long_objs

SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = so_long

all: libft printf $(NAME)

.PHONY: all bonus clean fclean re libft printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -Imlx_linux -c $< -o $@

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


