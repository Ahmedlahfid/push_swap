/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:54 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 14:44:33 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	rot(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack)
{
	rot(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	ft_putendl_fd("rrr", 1);
}

void	rrb(t_list **stack)
{
	rev_rot(stack);
	ft_putendl_fd("rrb", 1);
}
