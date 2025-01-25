/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:42:17 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 18:11:24 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

////////////GNL/////////////
size_t	ft_strlen(const char *s);
int		ft_isnewline(char *s);
char	*get_next_line(int fd);

void	check_instructions(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
void	execute_instruction(char *instruction, t_list **stack_a,
			t_list **stack_b);
void	msg_err(void);

////////////////////////// ERROR HANDLING ///////////////////////////

void	msg_err(void);
int		is_nbr(char *str);
int		is_duplicated(char **num);
void	free_split(char **split);
////////////////////////////////////////////////////////////////////

void	push_to_stack(t_list **stack, char **arg);
void	*arg_checker(int ac, char **av);
char	*joinargs(int ac, char **av);
int		beta_atoi(char *str, int neg, int i);

/////////////////////////// STACK ACTIONS ////////////////////////////

/// Basic Actions
void	swap(t_list **stack);
void	rev_rot(t_list **stack);
void	rot(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);

/// Swap Operations
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

/// Push Operations
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

/// Rotate Operations
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);

/// Reverse Rotate Operations
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *stack);

#endif
