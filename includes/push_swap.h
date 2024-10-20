/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msawada <msawada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:33:36 by msawada           #+#    #+#             */
/*   Updated: 2024/10/20 20:20:34 by msawada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_CODE 0

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int			num;
	t_stack		*next;
}				t_stack;

typedef struct s_list
{
	int			num;
	int			sort_a_count;
	int			sort_b_count;
	int			a_total;
	int			b_total;
}				t_list;

void	main_sort(t_stack **list_a, t_stack **list_b, int total);
void	ft_p(t_stack **list_a, t_stack **list_b);
void	ft_s(t_stack **list);
void	ft_r(t_stack **list);
void	ft_rr(t_stack **list);
void	add_node(t_stack **list, int num);
void	move_num(t_stack **list_a, t_stack **list_b, t_list *cheapest);
void	move_ra(t_stack **list_b, int sort_a_count);
void	move_rb(t_stack **list_b, int sort_b_count);
void	print_list(t_stack *list_a, t_stack *list_b);
void	find_cheap_num(t_stack *list_a, t_stack *list_b, t_list *cheapest);
void	ascending_order(t_stack **list_a, int total_a);
void	three_sort(t_stack **list_a);
void	four_sort(t_stack **list_a, t_stack **list_b);
void	five_sort(t_stack **list_a, t_stack **list_b);
void	free_node(t_stack **list);
int		find_big_num(t_stack *list);
int		find_small_num(t_stack *list);
int		atoi_arg(char *str, t_stack **list);
int		count_sort_a(t_stack *list, int num, int total);
int		count_sort_b(t_stack *list_b, int num, int total);
int		find_small_num(t_stack *list);
int		find_big_num(t_stack *list);
int		list_sorted(t_stack *list);
t_stack	*search_end(t_stack *list);

#endif
