/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:22:10 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 19:31:11 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9' || num > INT_MAX || num < INT_MIN)
		{
			write(1, "Error\n", 6);
			free_node(list);
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
			return (NULL);
		}
		list = list->next;
	}
	return (list);
}

// Create a new node
t_stack	*create_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

// Add a new node to the end of the list
void	add_node(t_stack **list, int num)
{
	t_stack	*new_node;
	t_stack	*end;

	new_node = create_node(num);
	if (new_node == NULL)
	{
		write(1, "Error\n", 6);
		free_node(list);
		exit(1);
	}
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	end = find_end_and_check_duplicates(*list, num);
	if (end == NULL)
	{
		free_node(list);
		exit(1);
	}
	end->next = new_node;
	return ;
}
