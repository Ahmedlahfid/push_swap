/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:53:42 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 10:30:15 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/////////////////////////// MAIN FUNCTIONS ///////////////////////////

void	push_to_stack(t_list **stack, char **arg);
void	*arg_checker(int ac, char **av);
char	*joinargs(int ac, char **av);
int		beta_atoi(char *str, int neg, int i);

////////////////////////// ERROR HANDLING ///////////////////////////

void	msg_err(void);
int		is_nbr(char *str);
int		is_duplicated(char **num); // Update return type to int
void	free_split(char **split);

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

/////////////////////////// SORTING FUNCTIONS ////////////////////////

void	handle_sorting(t_list **stack_a, t_list **stack_b, int size);
int		is_sorted(t_list *stack);

/// Sorting Small Stacks
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);

/// Sorting Large Stacks
void	sort_large_stack(t_list **stack_a, t_list **stack_b);

/////////////////////////// SORT HELPERS /////////////////////////////

/// Helpers for Sorting 4 and 5
int		find_min(t_list *stack);
void	move_to_top(t_list **stack, int value);
int		find_position(t_list *stack, int value);

/// Helpers for Sorting Large Stacks
void	normalize_stack(t_list **stack_a, t_list **stack_b, int range);
int		*sort_tab(t_list *stack_a);
int		*stack_to_tab(t_list *stack_a, int *tab);
void	move_largest_to_top(t_list **stack_b);
int		find_largest_index(t_list **stack);

/////////////////////////// DEBUG FUNCTIONS //////////////////////////

void	print_stack(t_list *stack);

#endif
