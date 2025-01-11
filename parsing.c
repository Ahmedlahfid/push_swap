/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahlahfid <ahlahfid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:41:13 by ahlahfid          #+#    #+#             */
/*   Updated: 2025/01/03 14:19:11 by ahlahfid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void msg_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
	
}


void is_nbr(char *str)
{
    int i = 0;
    int neg = 1;

    // Handle optional '+' or '-' sign
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i + 1] == '\0') // No digits after sign
            msg_err();
        if (str[i] == '-')
            neg = -1;
        i++;
    }

    // Validate number using mini_atoi
    mini_atoi(str, neg, i);
}

void mini_atoi(char *str, int neg, int i)
{
    long nb = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9') // Check if character is not a digit
            msg_err();
        nb = nb * 10 + (str[i] - '0'); // Build the number
        if ((nb * neg) > 2147483647 || (nb * neg) < -2147483648) // Check overflow
            msg_err();
        i++;
    }
}

void is_duplicated(char **num)
{
    int i = 0;
    int j;

    while (num[i])
    {
        j = i + 1;
        while (num[j])
        {
            if (ft_atoi(num[i]) == ft_atoi(num[j])) // Compare numbers
                msg_err(); // Duplicate found
            j++;
        }
        i++;
    }
}

