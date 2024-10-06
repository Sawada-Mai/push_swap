/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:22:10 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 17:00:23 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Excluding INT out of range and non-numeric characters
int	atoi_arg(char *str)
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
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9' || num > INT_MAX || num < INT_MIN)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}

// Only look for the last node
t_stack	*search_end(t_stack *list)
{
	if (list == NULL)
		return (NULL);

	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

// Find the last node and check for duplicates
t_stack	*find_end_and_check_duplicates(t_stack	*list, int num)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
		if (list->num == num)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		list = list->next;
	}
	return (list);
}

// Add a new node to the end of the list
void	add_node(t_stack **list, int num)
{
	t_stack	*new_node;
	t_stack	*end;

	new_node = create_node(num);
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	end = find_end_and_check_duplicates(*list, num);
	end->next = new_node;
	return ;
}

// Create a new node
t_stack	*create_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}
