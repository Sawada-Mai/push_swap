/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:05:42 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 21:26:14 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returuns where in list_b the number can be inserted
int	find_insert_position(t_stack *list_b, int num, int total)
{
	int		position;
	int		prev;
	t_stack	*current;

	if (list_b == NULL || total == 0)
		return (0);
	position = 0;
	prev = list_b->num;
	current = list_b;
	while (current != NULL && position < total)
	{
		if ((num > current->num && num < prev) || (num > current->num
				&& prev < current->num) || (prev < current->num && num < prev))
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
int	count_sort_a(t_stack *list, int num, int total)
{
	int	insert_position;

	insert_position = 0;
	if (list == NULL)
		return (0);
	while (!(list->num == num))
	{
		insert_position++;
		list = list->next;
	}
	if (insert_position <= (total - insert_position))
		return (insert_position);
	else
		return (-(total - insert_position));
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

// Stores the value of the node passed as argument to
// the structure and the number of moves required.
// The exact total number of moves for A and B is returned as the return value.
int	cost(t_stack *list_a, t_stack *list_b, t_stack *node, t_list *cheapest)
{
	cheapest->num = node->num;
	cheapest->sort_a_count = count_sort_a(list_a, node->num, cheapest->a_total);
	cheapest->sort_b_count = count_sort_b(list_b, node->num, cheapest->b_total);
	if (cheapest->sort_a_count < 0 && cheapest->sort_b_count < 0)
	{
		if (cheapest->sort_a_count < cheapest->sort_b_count)
			return (-(cheapest->sort_a_count));
		else
			return (-(cheapest->sort_b_count));
	}
	else if (cheapest->sort_a_count >= 0 && cheapest->sort_b_count >= 0)
	{
		if (cheapest->sort_a_count > cheapest->sort_b_count)
			return (cheapest->sort_a_count);
		else
			return (cheapest->sort_b_count);
	}
	else
	{
		if (cheapest->sort_a_count < 0)
			return (-(cheapest->sort_a_count) + cheapest->sort_b_count);
		else
			return (cheapest->sort_a_count + -(cheapest->sort_b_count));
	}
}

// First, the first number of moves is set as minimum vlue,
// and each time time a minimum value is reached,
// the number of minimum moves is updated.
// If the number of moves is the same,
// the one with the smaller number is given priority.
void	find_cheap_num(t_stack *list_a, t_stack *list_b, t_list *cheapest)
{
	int		cheap_count;
	int		sum_count;
	t_stack	*node;
	t_list	stock_node;

	cheap_count = INT_MAX;
	node = list_a;
	while (node != NULL)
	{
		stock_node = *cheapest;
		sum_count = cost(list_a, list_b, node, &stock_node);
		if (sum_count < cheap_count)
		{
			cheap_count = sum_count;
			*cheapest = stock_node;
		}
		else if (cheap_count == sum_count && cheapest->num > node->num)
		{
			cheap_count = sum_count;
			*cheapest = stock_node;
		}
		node = node->next;
	}
	return ;
}
