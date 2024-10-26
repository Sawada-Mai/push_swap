/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fewer_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:16:31 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 22:47:28 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack **list_a)
{
	int	sort_count;

	sort_count = count_sort_a(*list_a, find_big_num(*list_a), 3);
	if (list_a == NULL)
		return ;
	if (sort_count == 1)
	{
		ft_rr(list_a);
		write(1, "rra\n", 4);
	}
	else if (sort_count == 0)
	{
		ft_r(list_a);
		write(1, "ra\n", 3);
	}
	if ((*list_a)->num > (*list_a)->next->num)
	{
		ft_s(list_a);
		write(1, "sa\n", 3);
	}
	return ;
}

void	four_sub_sort(t_stack **list_a, t_stack **list_b)
{
	if ((*list_b)->num < (*list_a)->num
		|| search_end(*list_a)->num < (*list_b)->num)
		ft_p(list_b, list_a);
	else if ((*list_b)->num > (*list_a)->num
		&& (*list_b)->num < (*list_a)->next->num)
	{
		ft_r(list_a);
		write(1, "ra\n", 3);
		ft_p(list_b, list_a);
	}
	else
	{
		ft_rr(list_a);
		write(1, "rra\n", 4);
		ft_p(list_b, list_a);
	}
}

void	four_sort(t_stack **list_a, t_stack **list_b)
{
	ft_p(list_a, list_b);
	if (list_a == NULL || list_b == NULL)
		return ;
	write(1, "pb\n", 3);
	three_sort(list_a);
	if (list_a == NULL)
		return ;
	four_sub_sort(list_a, list_b);
	write(1, "pa\n", 3);
	ascending_order(list_a, 4);
	return ;
}

void	five_sort(t_stack **list_a, t_stack **list_b)
{
	int	sort_count;

	sort_count = count_sort_a(*list_a, find_small_num(*list_a), 5);
	if (list_a == NULL || list_b == NULL)
		return ;
	move_ra(list_a, sort_count);
	ft_p(list_a, list_b);
	write(1, "pb\n", 3);
	four_sort(list_a, list_b);
	ft_p(list_b, list_a);
	write(1, "pa\n", 3);
	ascending_order(list_a, 5);
	return ;
}
