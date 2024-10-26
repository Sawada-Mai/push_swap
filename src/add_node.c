/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:22:10 by msawada           #+#    #+#             */
/*   Updated: 2024/10/24 20:58:13 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	check_duplicates(t_stack *list, int num)
{
	int		flag;
	t_stack	*current;

	flag = 0;
	current = list;
	while (current != NULL)
	{
		if (current->num == num && flag == 0)
		{
			flag = 1;
		}
		else if (current->num == num)
		{
			write(1, "Error\n", 6);
			free_node(&list);
			exit(1);
		}
		current = current->next;
	}
	return (0);
}

// Find the last node and check for duplicates
t_stack	*find_end(t_stack *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
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
	end = find_end(*list);
	if (end == NULL)
	{
		write(1, "Error\n", 6);
		free_node(list);
		exit(1);
	}
	end->next = new_node;
	check_duplicates(*list, num);
	return ;
}
