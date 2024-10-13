/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:06:27 by msawada           #+#    #+#             */
/*   Updated: 2024/10/13 21:48:20 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Stores the value of the node passed as argument to
// the structure and the number of moves required.
// The exact total number of moves for A and B is returned as the return value.
int	cost(t_stack *list_a, t_stack *list_b, t_stack *node, t_list *cheapest)
{
	cheapest->num = node->num;
	cheapest->sort_a_count = count_sort_a(list_a, node->num, cheapest->a_total);
	cheapest->sort_b_count = count_sort_b(list_b, node->num, cheapest->b_total);
	// printf("chapest->a_total = %d\n", cheapest->a_total);
	printf("cheapest->num = %d\n\n", cheapest->num);
	printf("cheapest->sort_a_count = %d\n", cheapest->sort_a_count);
	printf("cheapest->sort_b_count = %d\n\n", cheapest->sort_b_count);
	if (cheapest->sort_a_count < 0 && cheapest->sort_b_count < 0)
	{
		if (cheapest->sort_a_count < cheapest->sort_b_count)
			return (-(cheapest->sort_a_count));
		else
			return (-(cheapest->sort_b_count));
	}
	else if (cheapest->sort_a_count > 0 || cheapest->sort_b_count > 0)
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

	cheap_count = 0;
	node = list_a;
	cheap_count = cost(list_a, list_b, node, cheapest);
	node = node->next;
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

int	list_sorted(t_stack *list)
{
	int	num;

	num = list->num;
	list = list->next;
	while (list != NULL)
	{
		if (num > list->num)
			return (0);
		num = list->num;
		list = list->next;
	}
	return (1);
}

void	ascending_order(t_stack **list_a)
{
	while (!list_sorted(*list_a))
	{
		ft_r(list_a);
		write(1, "ra\n", 3);
	}
}

// Move the smallest number of ,
// ovest to list_b until there are no more number on list_a.
// After all the numbers are moved, return the numbers to list_a.
void	main_sort(t_stack **list_a, t_stack **list_b, int total)
{
	t_list	cheapest;

	ft_p(list_a, list_b);
	ft_p(list_a, list_b);
	write(1, "pb\n", 3);
	write(1, "pb\n", 3);
	cheapest.a_total = total - 2;
	cheapest.b_total = 2;
	while (cheapest.a_total > 0)
	{
		find_cheap_num(*list_a, *list_b, &cheapest);
		// printf("cheapest->num = %d\n", cheapest.num);
		// printf("cheapest->sort_a_count = %d\n", cheapest.sort_a_count);
		// printf("cheapest->sort_b_count = %d\n", cheapest.sort_b_count);
		// move_num(list_a, list_b, &cheapest);
		ft_p(list_a, list_b);
		write(1, "pb\n", 3);
		cheapest.a_total--;
		cheapest.b_total++;
		exit(0);
	}
	// while (cheapest.b_total > 0)
	// {
	// 	ft_p(list_b, list_a);
	// 	write(1, "pa\n", 3);
	// 	cheapest.b_total--;
	// 	cheapest.a_total++;
	// }
	// ascending_order(list_a);
	return ;
}
