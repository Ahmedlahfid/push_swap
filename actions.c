/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:30:21 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 10:23:01 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	push(t_list **a_stack, t_list **b_stack)
{
	t_list	*tmp;

	if (*a_stack)
	{
		tmp = *a_stack;
		*a_stack = (*a_stack)->next;
		tmp->next = *b_stack;
		*b_stack = tmp;
	}
}

void	rev_rot(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack;
		*stack = tmp2;
	}
}

void	rot(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
}
