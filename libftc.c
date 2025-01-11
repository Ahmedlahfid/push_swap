/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:37:21 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/01 13:08:40 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *lstnew(void *data)
{
    t_node *head;

    head = malloc(sizeof(t_node));
    if (!head)
    return (NULL);
    
    head->data = data;
    head->next = NULL;
    
    return (head);
}
t_node *lstadd_back(t_node **lst, t_node *new)
{
    t_node *tmp;
    
    if(!lst || !new)
        return;
    if(!*lst)
    {
        *lst = new;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new;
    
}
void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write (fd, &c, 1);
}