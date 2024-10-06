/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:09:53 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 20:03:56 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_p(t_stack **list_a, t_stack **list_b)
{
	t_stack	*copy_b;

	if (!*list_a)
		return ;
	copy_b = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
	(*list_b)->next = copy_b;
	return ;
}

void	ft_s(t_stack **list)
{
	t_stack	*copy;

	if (!*list || !(*list)->next)
		return ;
	copy = *list;
	*list = (*list)->next;
	copy->next = (*list)->next;
	(*list)->next = copy;
	return ;
}

void	ft_r(t_stack **list)
{
	t_stack	*copy;
	t_stack	*end;


	if (!*list || !(*list)->next)
		return ;
	copy = *list;
	end = search_end(*list);
	end->next = *list;
	*list = (*list)->next;
	copy->next = NULL;
	return ;
}

void	ft_rr(t_stack **list)
{
	t_stack	*end;
	t_stack	*second_end;


	if (!*list || !(*list)->next)
		return ;
	end = *list;
	while (end->next != NULL)
	{
		second_end = end;
		end = end->next;
	}
	end->next = *list;
	*list = end;
	second_end->next = NULL;
	return ;
}
