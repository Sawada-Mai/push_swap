/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:01:49 by msawada           #+#    #+#             */
/*   Updated: 2024/10/13 16:46:20 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Shift elements DOWN
// Use the values of sort_a_count and sort_b_count stored in the structure.
// If both and 1 or more, perform simultaneous rotation,
// otherwise, rotate by itself.
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

// Shift elements UP
// Use the values of sort_a_count and sort_b_count stored in the structure.
// If both and 1 or more, perform simultaneous rotation,
// otherwise, rotate by itself.
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

// Rotate list_a by the number of times sort_a_count.
// If negative, shift the value down.
// If positive, shift the value up.
void	move_ra(t_stack **list_a, t_list *cheapest)
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

// Rotate list_b by the number of times sort_b_count.
// If negative, shift the value down.
// If positive, shift the value up.
void	move_rb(t_stack **list_b, t_list *cheapest)
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

// Branching on negative and positive combinations
// of sort_a_count and sort_b_count.
// If both are negative numbers, the move_rrr function is called.
// If both are positive numbers, the move_rr function is called.
// Otherwise, use the move_ra and move_rb functions.
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
		move_ra(&list_a, cheapest);
		move_rb(&list_b, cheapest);
	}
}
