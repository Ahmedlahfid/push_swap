/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_b_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:08:35 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 17:44:33 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_instruction(char *instruction, t_list **stack_a,
		t_list **stack_b)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(stack_b, stack_a);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(stack_b, stack_a);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		msg_err();
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp->content);
		free(temp);
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current && current->next)
	{
		if (*((int *)current->content) > *((int *)current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// void	print_stack(t_list *stack)
// {
// 	t_list	*current;

// 	current = stack;
// 	while (current)
// 	{
// 		printf("%d\n", *(int *)current->content);
// 		current = current->next;
// 	}
// }
