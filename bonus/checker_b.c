/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:43:12 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/25 14:05:29 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_to_stack(t_list **stack, char **arg)
{
	int	i;
	int	*value;

	i = 0;
	while (arg[i])
	{
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_lstclear(stack, free);
			free_split(arg);
			msg_err();
		}
		*value = ft_atoi(arg[i]);
		ft_lstadd_back(stack, ft_lstnew(value));
		i++;
	}
	free_split(arg);
}

char	*joinargs(int argc, char **argv)
{
	int		i;
	int		j;
	char	*args;
	char	*temp;

	i = 1;
	args = ft_strdup("");
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			free(args);
			msg_err();
		}
		temp = args;
		args = ft_strjoin(args, argv[i++] + j);
		free(temp);
		temp = args;
		args = ft_strjoin(args, " ");
		free(temp);
	}
	return (args);
}

void	*arg_checker(int ac, char **av)
{
	int		i;
	char	*join_args;
	char	**split_args;

	join_args = joinargs(ac, av);
	if (!join_args)
		msg_err();
	split_args = ft_split(join_args, ' ');
	free(join_args);
	if (!split_args)
		msg_err();
	i = 0;
	while (split_args[i])
	{
		if (!is_nbr(split_args[i]) || is_duplicated(split_args))
		{
			free_split(split_args);
			msg_err();
		}
		i++;
	}
	return (split_args);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	args = arg_checker(ac, av);
	if (!args)
		msg_err();
	push_to_stack(&stack_a, args);
	check_instructions(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
