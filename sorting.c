/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:25 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 10:20:57 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		sa(stack);
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_four(t_list **a_stack, t_list **b_stack)
{
	int	min;

	min = find_min(*a_stack);
	move_to_top(a_stack, min);
	pb(b_stack, a_stack);
	sort_three(a_stack);
	pa(b_stack, a_stack);
}

void	sort_five(t_list **a_stack, t_list **b_stack)
{
	int	min;

	min = find_min(*a_stack);
	move_to_top(a_stack, min);
	pb(b_stack, a_stack);
	min = find_min(*a_stack);
	move_to_top(a_stack, min);
	pb(b_stack, a_stack);
	sort_three(a_stack);
	pa(b_stack, a_stack);
	pa(b_stack, a_stack);
}
