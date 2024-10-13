/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:21:13 by msawada           #+#    #+#             */
/*   Updated: 2024/10/13 19:51:12 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stack *list_a, t_stack *list_b)
{
	int	i;

	i = 0;
	if (list_a == NULL && list_b == NULL)
	{
		return ;
	}
	while (list_a != NULL)
	{
		printf("index(%d) = ", i + 1);
		printf("%d\n", list_a->num);
		list_a = list_a->next;
		i++;
	}
	printf("\n");
	while (list_b != NULL)
	{
		printf("index(%d) = ", i + 1);
		printf("%d\n", list_b->num);
		list_b = list_b->next;
		i++;
	}
	printf("\n\n");
}
