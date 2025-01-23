/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:29:41 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 10:27:55 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

void	move_to_top(t_list **stack, int value)
{
	int	pos;
	int	size;

	pos = find_position(*stack, value);
	size = ft_lstsize(*stack);
	if (pos <= size / 2)
		while (*(int *)(*stack)->content != value)
			ra(stack);
	else
		while (*(int *)(*stack)->content != value)
			rra(stack);
}

int	find_position(t_list *stack, int value)
{
	int	position;

	position = 0;
	while (stack != NULL)
	{
		if (*(int *)stack->content == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	*stack_to_tab(t_list *stack_a, int *tab)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		tab[i] = *((int *)stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	return (tab);
}
