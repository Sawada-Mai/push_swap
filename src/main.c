/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:47:56 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 19:22:00 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	argument_branch(t_stack **list_a, t_stack **list_b, int argc)
{
	if (argc == 2)
		return ;
	else if (argc == 3)
		ascending_order(list_a, 2);
	else if (argc == 4)
		three_sort(list_a);
	else if (argc == 5)
		four_sort(list_a, list_b);
	else
		five_sort(list_a, list_b);
	return ;
}

// Free the entire list
void	free_list(t_stack **list)
{
	t_stack	*current;
	t_stack	*next_node;

	current = *list;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*list = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*list_a;
	t_stack	*list_b;

	i = 1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		write(1, "Error\n", 6);
	while (i < argc)
	{
		num = atoi_arg(argv[i], &list_a);
		add_node(&list_a, num);
		i++;
	}
	if (list_sorted(list_a) == 1)
		return (0);
	if (argc <= 6)
		argument_branch(&list_a, &list_b, argc);
	else
		main_sort(&list_a, &list_b, argc - 1);
	free_node(&list_a);
	return (0);
}
