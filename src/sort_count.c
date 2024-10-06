/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:05:42 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 20:19:22 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_insert_position(t_stack *list_b, int num, int total)
{
	int			position;
	int			prev;
	t_stack		*current;

	if (list_b == NULL || total == 0)
		return (0);
	position = 0;
	prev = list_b->num;
	current = list_b;
	while (current != NULL && position < total)
	{
		if ((num > current->num && num < prev)
			|| (num > current->num && prev < current->num)
			|| (prev < current->num && num < prev))
		{
			return (position);
		}
		prev = current->num;
		current = current->next;
		position++;
	}
	return (0);
}

// Positive to shift the value up, negative to shift the value down
int	count_sort_a(t_stack *list, t_stack *node, int total)
{
	int	num;

	num = 0;
	while (!(list == node))
	{
		num++;
		list = list->next;
	}
	if (num <= (total - num))
		return (num);
	else
		return (-(total - num));
}

// Positive to shift the value up, negative to shift the value down
int	count_sort_b(t_stack *list_b, int num, int total)
{
	int	insert_position;

	insert_position = find_insert_position(list_b, num, total);
	if (insert_position <= total / 2)
	{
		return (insert_position);
	}
	else
	{
		return (-(total - insert_position));
	}
}
