CC = cc
CFLAGS += -Wall -Wextra -Werror
LDFLAGS += -L./libft -L./printf
LIBS += -lft -lftprintf

SRC_DIR = ./src
OBJ_DIR = ./objs

SERVER_SRC := $(wildcard $(SRC_DIR)/server/*.c)
CLIENT_SRC := $(wildcard $(SRC_DIR)/client/*.c)

SERVER_OBJ := $(SERVER_SRC:$(SRC_DIR)/server/%.c=$(OBJ_DIR)/server/%.o)
CLIENT_OBJ := $(CLIENT_SRC:$(SRC_DIR)/client/%.c=$(OBJ_DIR)/client/%.o)

SERVER_NAME = server
CLIENT_NAME = client

all: libft printf $(SERVER_NAME) $(CLIENT_NAME)

.PHONY: all clean fclean re libft printf

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER_NAME) $(LDFLAGS) $(LIBS)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT_NAME) $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/server/%.o: $(SRC_DIR)/server/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

$(OBJ_DIR)/client/%.o: $(SRC_DIR)/client/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

libft:
	$(MAKE) -C ./libft

printf:
	$(MAKE) -C ./printf

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./printf clean

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./printf fclean

re: fclean all