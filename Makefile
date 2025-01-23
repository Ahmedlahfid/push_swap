# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 10:02:20 by ahlahfid          #+#    #+#              #
#    Updated: 2025/01/23 14:06:49 by ahlahfid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Compiler and flags
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = actions.c  operations.c operations2.c operations3.c parsing.c push_swap.c sorting.c sort_help.c sort_large.c push_swap_h.c

BONUS_SRCS =  bonus/actions.c \
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

# Colors for output
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m
BLUE = \033[1;34m 

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling libft."
	@make -C libft 
	@echo "$(GREEN)Libft compiled successfully ✅$(RESET)"
	@echo "$(BLUE)Compiling push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap compiled successfully ✅$(RESET)"

bonus: $(BONUS_OBJS)
	@echo "$(BLUE)Compiling bonus...$(RESET)"
	@make -C libft
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(GREEN)Bonus compiled successfully ✅$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@make clean -C libft
	@echo "$(GREEN)Object files cleaned ✅$(RESET)"

fclean: clean
	@echo "$(RED)Performing full cleanup...$(RESET)"
	@rm -f $(NAME) $(BONUS)
	@make fclean -C libft 
	@echo "$(GREEN)Full cleanup completed ✅$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

