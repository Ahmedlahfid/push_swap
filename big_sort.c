/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:01 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/14 15:05:44 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	range;

	range = 0;
	if (ft_lstsize(*stack_a) >= 6
		&& ft_lstsize(*stack_a) <= 20)
		range = 4;
	else if (ft_lstsize(*stack_a) <= 100)
		range = 15;
	else if (ft_lstsize(*stack_a) <= 500)
		range = 40;
	ft_norm(stack_a, stack_b, range);
	while (*stack_b)
	{
		big_to_up(stack_b);
		pa(stack_b, stack_a);
	}
}
void	ft_norm(t_list **stack_a, t_list **stack_b, int range)
{
	int	*tab;
	int	i;

	i = 0;
	tab = sort_tab(*stack_a);
	while (*stack_a)
	{
		if (*(int *)(*stack_a)->content <= tab[i])
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if (*(int *)(*stack_a)->content > tab[i]
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

void	big_to_up(t_list **stack_b)
{
	int	i;
	int	stack_size;

	// Get the size of stack_b
	stack_size = ft_lstsize(*stack_b);

	while (1)
	{
		// Find the index of the largest element
		i = find_big(stack_b);

		// If the index is 0, the largest element is already at the top, break the loop
		if (i == 0)
			break ;

		// If the largest element is closer to the top, rotate normally
		else if (i <= stack_size / 2)
			rb(stack_b);

		// If the largest element is closer to the bottom, rotate in reverse
		else
			rrb(stack_b);
	}
}

int	find_big(t_list **stack)
{
	int		max;
	t_list	*tmp;
	int		i;
	int		index;

	tmp = *stack;
	max = *((int *)tmp->content);
	index = 0;
	i = 0;

	// Iterate through the list to find the maximum value
	while (tmp)
	{
		if (*((int *)tmp->content) > max)
		{
			max = *((int *)tmp->content);
			index = i;  // Store the index of the maximum value
		}
		tmp = tmp->next;
		i++;
	}

	// Return the index of the maximum value
	return (index);
}
