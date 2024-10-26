/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:22:10 by msawada           #+#    #+#             */
/*   Updated: 2024/10/24 21:42:44 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	change_num(char *str, int sign, t_stack **list)
{
	int		i;
	long	num;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\n", 6);
			free_node(list);
			exit(1);
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		free_node(list);
		exit(1);
	}
	return ((int)num);
}

// Excluding INT out of range and non-numeric characters
int	atoi_arg(char *str, t_stack **list)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		write(1, "Error\n", 6);
		free_node(list);
		exit(1);
	}
	num = change_num(&str[i], sign, list);
	return (num);
}
