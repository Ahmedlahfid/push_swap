/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:25:23 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 12:12:30 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_list **stack)
{
	swap(stack);
}

void	sb(t_list **stack)
{
	swap(stack);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
