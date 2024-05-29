CC = cc
CFLAGS += -Wall -Werror -Wextra -g

SRC_DIR = ./src
OBJ_DIR = ./philo_objs

SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = so_long

all: $(NAME)

.PHONY: all bonus clean fclean re

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)-o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all


