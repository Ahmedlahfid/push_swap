/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:06:25 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/10 16:34:10 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_list **stack)
{
    if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
        sa(stack); // Swap the two elements if they are out of order
}


void sort_three(t_list **stack)
{
    int first = *(int *)(*stack)->content;
    int second = *(int *)(*stack)->next->content;
    int third = *(int *)(*stack)->next->next->content;

    if (first > second && second < third && first < third) // Case: 2 1 3
        sa(stack); 
    else if (first > second && second > third) // Case: 3 2 1
    {
        sa(stack);
        rra(stack); 
    }
    else if (first > second && second < third && first > third) // Case: 3 1 2
        ra(stack); 
    else if (first < second && second > third && first < third) // Case: 1 3 2
    {
        sa(stack);
        ra(stack);
    }
    else if (first < second && second > third && first > third) // Case: 2 3 1
        rra(stack);
}
void sort_four(t_list **a_stack, t_list **b_stack)
{
    int min;

    
    min = find_min(*a_stack);
    move_to_top(a_stack, min);
    pb(b_stack, a_stack);

    sort_three(a_stack);

    pa(b_stack, a_stack);
}
void sort_five(t_list **a_stack, t_list **b_stack)
{
    int min;

    // Step 1: Push the smallest element to b
    min = find_min(*a_stack); // Find the smallest element
    move_to_top(a_stack, min); // Bring it to the top of a_stack
    pb(b_stack, a_stack); // Push it to b_stack

    // Step 2: Push the second smallest element to b
    min = find_min(*a_stack); // Find the next smallest element
    move_to_top(a_stack, min); // Bring it to the top of a_stack
    pb(b_stack, a_stack); // Push it to b_stack

    // Step 3: Sort the remaining three elements in a
    sort_three(a_stack);

    // Step 4: Push back two smallest elements from b to a
    pa(b_stack, a_stack);
    pa(b_stack, a_stack);
}

