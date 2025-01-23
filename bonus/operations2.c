/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:00:54 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 12:12:27 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_list **stack)
{
	rot(stack);
}

void	rb(t_list **stack)
{
	rot(stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}

void	rrb(t_list **stack)
{
	rev_rot(stack);
}
