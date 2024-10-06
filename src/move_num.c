/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:01:49 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 21:02:00 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_rrr(t_stack **list_a, t_stack **list_b, t_list *cheapest)
{
	while (cheapest->sort_a_count < 0 || cheapest->sort_b_count < 0)
	{
		if (cheapest->sort_a_count < 0 && cheapest->sort_b_count < 0)
		{
			cheapest->sort_a_count++;
			cheapest->sort_b_count++;
			ft_rr(&list_a);
			ft_rr(&list_b);
			write(1, "rrr\n", 4);
		}
		else if (cheapest->sort_a_count < 0)
		{
			cheapest->sort_a_count++;
			ft_rr(&list_a);
			write(1, "rra\n", 4);
		}
		else
		{
			cheapest->sort_b_count++;
			ft_rr(&list_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	move_rr(t_stack **list_a, t_stack **list_b, t_list *cheapest)
{
	while (cheapest->sort_a_count >= 0 || cheapest->sort_b_count >= 0)
	{
		if (cheapest->sort_a_count > 0 && cheapest->sort_b_count > 0)
		{
			cheapest->sort_a_count--;
			cheapest->sort_b_count--;
			ft_r(&list_a);
			ft_r(&list_b);
			write(1, "rr\n", 3);
		}
		else if (cheapest->sort_a_count > 0)
		{
			cheapest->sort_a_count--;
			ft_r(&list_a);
			write(1, "ra\n", 3);
		}
		else
		{
			cheapest->sort_b_count--;
			ft_r(&list_b);
			write(1, "rb\n", 3);
		}
	}
}

void	move_aa(t_stack **list_a, t_list *cheapest)
{
	while (cheapest->sort_a_count != 0)
	{
		if (cheapest->sort_a_count < 0)
		{
			cheapest->sort_a_count++;
			ft_rr(&list_a);
			write(1, "rra\n", 4);
		}
		else
		{
			cheapest->sort_a_count--;
			ft_r(&list_a);
			write(1, "ra\n", 3);
		}
	}
}

void	move_ab(t_stack **list_b, t_list *cheapest)
{
	while (cheapest->sort_b_count != 0)
	{
		if (cheapest->sort_b_count < 0)
		{
			cheapest->sort_b_count++;
			ft_rr(&list_b);
			write(1, "rrb\n", 4);
		}
		else
		{
			cheapest->sort_b_count--;
			ft_r(&list_b);
			write(1, "rb\n", 3);
		}
	}
}

void	move_num(t_stack **list_a, t_stack **list_b, t_list *cheapest)
{
	if (cheapest->sort_a_count < 0 && cheapest->sort_b_count < 0)
	{
		move_rrr(&list_a, &list_b, cheapest);
	}
	else if (cheapest->sort_a_count >= 0 && cheapest->sort_b_count >= 0)
	{
		move_rr(&list_a, &list_b, cheapest);
	}
	else
	{
		move_aa(&list_a, cheapest);
		move_ab(&list_b, cheapest);
	}
}