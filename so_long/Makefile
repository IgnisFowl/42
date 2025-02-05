NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I.

SRC = main.c map_read.c map_check.c map_elements.c screen_init.c \
      screen_render.c screen_objects.c screen_free.c screen_moves.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX is now linked system-wide
LDFLAGS = -L./libraries/MinilibX -L/opt/homebrew/lib -lmlx -lXext -lX11

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -O3 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
