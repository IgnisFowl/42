NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = ft_printf.c ft_format.c ft_hex.c ft_int.c ft_uns.c ft_str.c ft_ptr.c
SRCS_BONUS = ft_printf_bonus.c ft_format_bonus.c ft_hex_bonus.c ft_int_bonus.c ft_uns_bonus.c ft_str_bonus.c ft_ptr_bonus.c

OBJ_DIR = src/objs
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS_PATH = $(addprefix $(OBJ_DIR)/, $(OBJS))
OBJS_PATH_BONUS = $(addprefix $(OBJ_DIR)/, $(OBJS_BONUS))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Ensure object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Default rule
all: $(LIBFT) $(NAME)

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build the main library
$(NAME): $(OBJS_PATH) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_PATH)

# Build the bonus library
bonus: $(OBJS_PATH_BONUS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_PATH_BONUS)

# Compile objects
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rules
clean:
	rm -f $(OBJ_DIR)/*.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus