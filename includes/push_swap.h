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

typedef struct s_list {
	int							num;
	int							sort_a_count;
	int							sort_b_count;
	int							a_total;
	int							b_total;
}	t_list;


int count_sort(t_stack *list_b, int num, int total);
t_stack *search_end(t_stack *list);
t_stack *find_end_and_check_duplicates(t_stack *list, int num);
int	atoi_arg(char *str);
int	count_move_up(t_stack *list, t_stack *node, int total);
void main_sort(t_stack **list_a, t_stack **list_b, int a_total);
int duplicate_check(t_stack *list);
void sort_third_num(t_stack **list_a);
int	list_sorted(t_stack *list);
void	add_node(t_stack **list, int num);
t_stack *create_node(int num);
int find_insert_position(t_stack *list_b, int num, int total);
void	sort_list_a(t_stack **list_a, int num, int total);
void sort_list_b(t_stack **list_b, int num, int total);
void ft_p(t_stack **list_a, t_stack **list_b);
void ft_s(t_stack **list);
void ft_r(t_stack **list);
void ft_rr(t_stack **list);

void	print_list(t_stack *list);


#endif