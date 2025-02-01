NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c parse_arg.c utils.c list_utils.c list_more_utils.c instruct_p.c instruct_rr.c instruct_rrr.c instruct_ss.c simple.c radix.c ft_atol.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a # Path to your libft.a file
INCLUDE = -I./include # Include your headers

all: $(LIBFT) $(NAME)

# Ensure libft.a is built before building the project
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build the main executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean only object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full cleanup, including libft and binary
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
