#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack {
	int							num;
	struct s_stack	*next;
}	t_stack;

// num: Number of nodes in list_a
// sort_a_count: Number of nodes in list_a
// sort_b_count: Number of nodes in list_b
// a_total: Number of nodes in list_a
// b_total: Number of nodes in list_b
typedef struct s_list {
	int							num;
	int							sort_a_count;
	int							sort_b_count;
	int							a_total;
	int							b_total;
}	t_list;

void	main_sort(t_stack **list_a, t_stack **list_b, int total);
void	ft_p(t_stack **list_a, t_stack **list_b);
void	ft_s(t_stack **list);
void	ft_r(t_stack **list);
void	ft_rr(t_stack **list);
void	add_node(t_stack **list, int num);
void	move_num(t_stack **list_a, t_stack **list_b, t_list *cheapest);
void	print_list(t_stack *list_a, t_stack *list_b);
int		atoi_arg(char *str);
int		count_sort_a(t_stack *list, int num, int total);
int		count_sort_b(t_stack *list_b, int num, int total);
t_stack	*search_end(t_stack *list);

#endif