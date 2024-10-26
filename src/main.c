/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:47:56 by msawada           #+#    #+#             */
/*   Updated: 2024/10/25 19:23:01 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	argument_branch(t_stack **list_a, t_stack **list_b, int count)
{
	if (list_a == NULL || list_b == NULL)
		return ;
	else
	{
		if (count == 2)
			return ;
		else if (count == 3)
			ascending_order(list_a, 2);
		else if (count == 4)
			three_sort(list_a);
		else if (count == 5)
			four_sort(list_a, list_b);
		else
			five_sort(list_a, list_b);
	}
	return ;
}

// Free the entire list
void	free_list(t_stack **list)
{
	t_stack	*current;
	t_stack	*next_node;

	if (list == NULL)
		return ;
	current = *list;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*list = NULL;
}

void	sort_type(int argc, t_stack *list_a, t_stack *list_b)
{
	if (list_sorted(list_a) == 1)
	{
		free_node(&list_a);
		return ;
	}
	else if (argc <= 6)
		argument_branch(&list_a, &list_b, argc);
	else
		main_sort(&list_a, &list_b, argc - 1);
	free_node(&list_a);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	int		count;
	t_stack	*list_a;
	t_stack	*list_b;

	i = 1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		count = make_list_argv(&list_a, argv[1]);
	else
	{
		while (i < argc)
		{
			make_list(&list_a, argv[i]);
			i++;
		}
		count = argc;
	}
	if (list_a != NULL)
		sort_type(count, list_a, list_b);
	return (0);
}
