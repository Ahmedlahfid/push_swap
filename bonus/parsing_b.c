/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:41:13 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/23 12:55:00 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	msg_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_nbr(char *str)
{
	int	i;
	int	neg;
	int	o;

	i = 0;
	neg = 1;
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (0);
		if (str[0] == '-')
			neg = -1;
		i++;
	}
	o = beta_atoi(str, neg, i);
	return (o);
}

int	beta_atoi(char *str, int neg, int i)
{
	long	nb;

	nb = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i] - '0');
		if ((nb * neg) > 2147483647 || (nb * neg) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicated(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = i + 1;
		while (num[j])
		{
			if (ft_atoi(num[i]) == ft_atoi(num[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
