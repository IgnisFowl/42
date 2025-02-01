# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include

# Source files
SRCS = ft_printf.c ft_format.c ft_hex.c ft_int.c ft_uns.c ft_str.c ft_ptr.c
SRCS_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Object files
OBJS = $(addprefix objs/, $(SRCS:.c=.o) $(SRCS_LIBFT:.c=.o))

# Library
LIBFT = libft.a

# Create object directory if it doesn't exist
$(shell mkdir -p objs)

# Default rule to build the final library
all: $(LIBFT)

# Build the libft.a library
$(LIBFT): $(OBJS)
	ar rcs $(LIBFT) $(OBJS)

# Compile object files
objs/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean rules
clean:
	rm -f objs/*.o

fclean: clean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
