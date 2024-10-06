/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:21:13 by msawada           #+#    #+#             */
/*   Updated: 2024/10/06 16:21:19 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stack *list)
{
	int	i;

	i = 0;
	if (list == NULL)
	{
		return ;
	}
	while (list != NULL)
	{
		printf("index(%d) = ", i + 1);
		printf("%d\n", list->num);
		list = list->next;
		i++;
	}
	printf("\n");
}
