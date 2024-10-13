/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:47:56 by msawada           #+#    #+#             */
/*   Updated: 2024/10/13 21:13:42 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*list_a;
	t_stack	*list_b;

	i = 1;
	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		write(1, "Error\n", 6);
	while (i < argc)
	{
		add_node(&list_a, atoi_arg(argv[i]));
		i++;
	}
	// if (argc == 4)
	// 	sort_third_num(&list_a);
	main_sort(&list_a, &list_b, argc - 1);
	// ascending_order(list_a);
	return (0);
}
