/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:21:00 by msawada           #+#    #+#             */
/*   Updated: 2024/10/25 19:50:36 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_list(t_stack **list_a, char *argv)
{
	int	num;

	num = atoi_arg(argv, list_a);
	add_node(list_a, num);
	return ;
}

void	make_node_argv(t_stack **list_a, int j, char *argv)
{
	int		i;
	char	str[12];

	i = 0;
	while (argv[j] != ' ' && argv[j] != '\0')
	{
		str[i] = argv[j];
		i++;
		j++;
		if (i > 12)
			error_free_node(list_a);
	}
	str[i] = '\0';
	add_node(list_a, atoi_arg(str, list_a));
	return ;
}

int	make_list_argv(t_stack **list_a, char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			i++;
		else
		{
			make_node_argv(list_a, i, argv);
			count++;
			while (argv[i] != ' ' && argv[i] != '\0')
			{
				i++;
			}
		}
	}
	return (count + 1);
}
