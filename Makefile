# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 10:02:20 by ahlahfid          #+#    #+#              #
#    Updated: 2025/01/25 15:20:22 by ahlahfid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = actions.c operations.c operations2.c operations3.c parsing.c \
       push_swap.c sorting.c sort_help.c sort_large.c push_swap_h.c

BONUS_SRCS = bonus/actions.c \
             bonus/checker_b_h.c \
             bonus/checker_b.c \
             bonus/get_next_line_utils.c \
             bonus/get_next_line.c \
             bonus/operations.c \
             bonus/operations2.c \
             bonus/operations3.c \
             bonus/parsing_b.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
LIBFT = -Llibft -lft
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus

