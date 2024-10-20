/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:51:45 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 19:32:41 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_big_num(t_stack *list)
{
	int	biggest;

	biggest = INT_MIN;
	while (list != NULL)
	{
		if (list->num > biggest)
			biggest = list->num;
		list = list->next;
	}
	return (biggest);
}

int	find_small_num(t_stack *list)
{
	int	smallest;

	smallest = INT_MAX;
	while (list != NULL)
	{
		if (list->num < smallest)
			smallest = list->num;
		list = list->next;
	}
	return (smallest);
}
