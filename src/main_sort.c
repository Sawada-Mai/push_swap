/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:06:27 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 18:52:13 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ascending_order(t_stack **list_a, int total_a)
{
	int	sort_count;

	sort_count = count_sort_a(*list_a, find_small_num(*list_a), total_a);
	if (sort_count < 0)
	{
		while (sort_count < 0)
		{
			ft_rr(list_a);
			write(1, "rra\n", 4);
			sort_count++;
		}
	}
	else
	{
		while (sort_count > 0)
		{
			ft_r(list_a);
			write(1, "ra\n", 3);
			sort_count--;
		}
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
		move_num(list_a, list_b, &cheapest);
		ft_p(list_a, list_b);
		write(1, "pb\n", 3);
		cheapest.a_total--;
		cheapest.b_total++;
	}
	while (cheapest.b_total-- > 0)
	{
		ft_p(list_b, list_a);
		write(1, "pa\n", 3);
		cheapest.a_total++;
	}
	ascending_order(list_a, cheapest.a_total);
	return ;
}
