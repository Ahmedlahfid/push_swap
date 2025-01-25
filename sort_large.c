/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:01 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/24 13:13:06 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_stack(t_list **stack_a, t_list **stack_b)
{
	int	range;

	range = 0;
	if (ft_lstsize(*stack_a) >= 6 && ft_lstsize(*stack_a) <= 20)
		range = 4;
	else if (ft_lstsize(*stack_a) <= 100)
		range = 15;
	else if (ft_lstsize(*stack_a) <= 500)
		range = 40;
	normalize_stack(stack_a, stack_b, range);
	while (*stack_b)
	{
		move_largest_to_top(stack_b);
		pa(stack_b, stack_a);
	}
}

void	normalize_stack(t_list **stack_a, t_list **stack_b, int range)
{
	int	*tab;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	tab = sort_tab(*stack_a);
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content <= tab[i])
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if (i + range < size && *(int *)(*stack_a)->content > tab[i]
			&& *(int *)(*stack_a)->content <= tab[range + i])
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
	free(tab);
}

int	*sort_tab(t_list *stack_a)
{
	int	*tab;
	int	i;
	int	size;
	int	swap;

	i = 0;
	size = ft_lstsize(stack_a);
	tab = malloc(sizeof(int) * ft_lstsize(stack_a));
	tab = stack_to_tab(stack_a, tab);
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	move_largest_to_top(t_list **stack_b)
{
	int	i;
	int	stack_size;

	stack_size = ft_lstsize(*stack_b);
	while (1)
	{
		i = find_largest_index(stack_b);
		if (i == 0)
			break ;
		else if (i <= stack_size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

int	find_largest_index(t_list **stack)
{
	int		max;
	t_list	*tmp;
	int		i;
	int		index;

	tmp = *stack;
	max = *((int *)tmp->content);
	index = 0;
	i = 0;
	while (tmp)
	{
		if (*((int *)tmp->content) > max)
		{
			max = *((int *)tmp->content);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}
