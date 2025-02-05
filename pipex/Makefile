NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utils.c execute.c custom_split.c # Add your other source files here (e.g., pipex.c, utils.c)
OBJ = $(SRC:.c=.o)
LIBFTPRINTF = ./libftprintf.a # Path to your libftprintf.a file
INCLUDE = -I./include # Include your pipex.h and other headers

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all
