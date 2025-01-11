/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:53:42 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/10 15:18:24 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H


# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include "./libft/libft.h"

# define PUSH_SWAP_H

//////main//////
void push_to_stack(t_list **stack, char **arg);
void    *arg_checker(int ac, char **av);
char	*joinargs(int ac, char **av);
void mini_atoi(char *str, int neg, int i);

///////err//////
void msg_err(void);
void is_nbr(char *str);
void	is_duplicated(char **num);

//////actions/////

void    swap(t_list **stack);
void	rev_rot(t_list **stack);
void rot(t_list **stack);
void push(t_list **a_stack, t_list **b_stack);

///////////operation//////////
/// swap
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
/// push
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
/// rotate
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
/// reverse rotate
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

/// sort
void sort_two(t_list **stack);
void sort_three(t_list **stack);
void sort_four(t_list **a_stack, t_list **b_stack);
void sort_five(t_list **a_stack, t_list **b_stack);

//^^^^^^^^^^//
int find_position(t_list *stack, int value);
void move_to_top(t_list **stack, int value);
int find_min(t_list *stack);



#endif
