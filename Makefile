NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# add files when u add function in them <3
SRC = main.c parse.c stack_utils.c parse_number.c 
OBJ = $(SRC:%.c=$(BIN)/%.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

BIN = bin

all: $(NAME)

$(BIN)/%.o: %.c
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	make -C $(LIBFT_DIR)
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
clean:
	rm -fr $(BIN)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all clean fclean re
