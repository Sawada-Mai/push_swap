/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:41:35 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 19:32:30 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_node(t_stack **list)
{
	int		i;
	t_stack	*temp;
	t_stack	*current;

	if (list == NULL || *list == NULL)
		return ;
	current = *list;
	i = 0;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		i++;
	}
	*list = NULL;
}
