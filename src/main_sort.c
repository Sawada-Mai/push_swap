/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:06:27 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 21:26:03 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	cost(t_stack *list_a, t_stack *list_b, t_stack *node, t_list *cheapest)
{
	cheapest->num = node->num;
	cheapest->sort_a_count = count_sort_a(list_a, node, cheapest->a_total);
	cheapest->sort_b_count = count_sort_b(list_b, node->num, cheapest->b_total);
	if (cheapest->sort_a_count < 0 && cheapest->sort_b_count < 0)
	{
		if (cheapest->sort_a_count < cheapest->sort_b_count)
			return (-(cheapest->sort_a_count));
		else
			return (-(cheapest->sort_b_count));
	}
	else if (cheapest->sort_a_count >= 0 || cheapest->sort_b_count >= 0)
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

void	find_cheap_num(t_stack *list_a, t_stack *list_b, t_list *cheapest)
{
	int		cheap_count;
	int		sum_count;
	t_stack	*node;
	t_list	*stock_node;

	cheap_count = 0;
	node = list_a;
	cheap_count = cost(list_a, list_b, node, &cheapest);
	stock_node = cheapest;
	while (node != NULL)
	{
		sum_count = cost(list_a, list_b, node, &stock_node);
		if (sum_count < cheap_count)
		{
			cheap_count = sum_count;
			cheapest = stock_node;
		}
		else if (cheap_count == sum_count && stock_node->num > node->num)
		{
			cheap_count = sum_count;
			cheapest = stock_node;
		}
		node = node->next;
	}
	return ;
}

void	main_sort(t_stack **list_a, t_stack **list_b, int a_total)
{
	t_list	*cheapest;

	ft_p(list_a, list_b);
	ft_p(list_a, list_b);
	cheapest->a_total = a_total;
	cheapest->b_total = 2;
	while (a_total > 0)
	{
		find_cheap_num(*list_a, *list_b, &cheapest);
		cheapest->a_total--;
		cheapest->b_total++;
		move_num(list_a, list_b, cheapest);
	}
	while (cheapest->b_total > 0)
	{
		ft_p(list_b, list_a);
		write(1, "pa\n", 3);
		cheapest->b_total--;
		cheapest->a_total++;
	}
	return ;
}

