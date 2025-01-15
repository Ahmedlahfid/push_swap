/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:18:25 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/14 11:59:06 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void sort_big(t_list **stack_a, t_list **stack_b)
// {
//     int size = ft_lstsize(*stack_a);
//     int chunk_size;
//     int *sorted_array;

//     sorted_array = sort_tab(*stack_a);
//     if (!sorted_array)
//         return;

//     if (size <= 100)
//         chunk_size = size / 5;
//     else
//         chunk_size = size / 11;

//     push_chunks(stack_a, stack_b, sorted_array, size, chunk_size);
//     push_back_to_a(stack_a, stack_b);

//     free(sorted_array);
// }

// void push_chunks(t_list **stack_a, t_list **stack_b, int *sorted, int size, int chunk_size)
// {
//     int start = 0;
//     int end = chunk_size;

//     while (*stack_a)
//     {
//         if (end > size)
//             end = size;
        
//         push_chunk(stack_a, stack_b, sorted, start, end);
        
//         start = end;
//         end += chunk_size;
//     }
// }

// void push_chunk(t_list **stack_a, t_list **stack_b, int *sorted, int start, int end)
// {
//     int value;
//     int mid = (start + end) / 2;
//     int pushed = 0;
//     int chunk_size = end - start;

//     while (*stack_a && pushed < chunk_size)
//     {
//         value = *(int *)(*stack_a)->content;
//         int i = find_index(value, sorted, ft_lstsize(*stack_a));
        
//         if (i >= start && i < end)
//         {
//             pb(stack_a, stack_b);
//             if (i < mid)
//                 rb(stack_b);
//             pushed++;
//         }
//         else
//         {
//             ra(stack_a);
//         }

//         // Break if we've gone through the entire stack without pushing
//         if (pushed == 0 && ft_lstsize(*stack_a) <= 3)
//             break;
//     }
// }


// void push_back_to_a(t_list **stack_a, t_list **stack_b)
// {
//     int max;

//     while (*stack_b)
//     {
//         max = find_max(*stack_b);
//         move_to_top(stack_b, max);
//         pa(stack_a, stack_b);
//     }
// }

// int find_index(int value, int *sorted, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (sorted[i] == value)
//             return i;
//     }
//     return -1;
// }

// // sort_tab function
// int *sort_tab(t_list *stack_a)
// {
//     int *tab;
//     int i;
//     int size;
//     int swap;

//     i = 0;
//     size = ft_lstsize(stack_a);
//     tab = malloc(sizeof(int) * size);
//     if (!tab)
//         return (NULL);
    
//     // Copy stack elements to array
//     t_list *temp = stack_a;
//     while (temp)
//     {
//         tab[i] = *(int *)temp->content;
//         temp = temp->next;
//         i++;
//     }

//     // Bubble sort
//     i = 0;
//     while (i < size - 1)
//     {
//         if (tab[i] > tab[i + 1])
//         {
//             swap = tab[i];
//             tab[i] = tab[i + 1];
//             tab[i + 1] = swap;
//             i = 0;
//         }
//         else
//             i++;
//     }
//     return (tab);
// }

// // find_max function
// int find_max(t_list *stack)
// {
//     int max;
    
//     if (!stack)
//         return (0);
    
//     max = *(int *)stack->content;
//     while (stack)
//     {
//         if (*(int *)stack->content > max)
//             max = *(int *)stack->content;
//         stack = stack->next;
//     }
//     return (max);
// }


