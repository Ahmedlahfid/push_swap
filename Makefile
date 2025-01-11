# Variables
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = actions.c helpers.c operations.c parsing.c push_swap.c sorting.c sort_help.c
OBJS = $(SRCS:.c=.o)
LIBFT = -Llibft -lft  # Correctly link to libft.a
INCLUDES = -I.

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
