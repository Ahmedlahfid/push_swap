/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:29:41 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/09 18:02:56 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_list *stack)
{
    int min = *(int *)stack->content;
    while (stack)
    {
        if (*(int *)stack->content < min)
            min = *(int *)stack->content;
        stack = stack->next;
    }
    return min;
}

void move_to_top(t_list **stack, int value)
{
    int pos = find_position(*stack, value);
    int size = ft_lstsize(*stack);

    if (pos <= size / 2)
        while (*(int *)(*stack)->content != value)
            ra(stack); 
    else
        while (*(int *)(*stack)->content != value)
            rra(stack);
}

int find_position(t_list *stack, int value)
{
    int position = 0;

    while (stack != NULL)
    {
        if (*(int *)stack->content == value) // Compare the value at the current node
            return position; // Return the current index if value is found
        stack = stack->next; // Move to the next node
        position++;
    }

    return -1; // Return -1 if the value is not found in the list
}


