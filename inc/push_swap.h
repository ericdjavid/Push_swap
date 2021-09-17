/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:38:52 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/13 11:39:00 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# define RB_STRAT 0
# define RRB_STRAT 1

typedef enum s_status {
	FAILURE,
	SUCCESS
} t_status;

typedef enum s_bool {
	FALSE,
	TRUE
} t_bool;

typedef struct s_element {
	int	number;
	int index;
	int count_for_sort;
	struct s_element *next_one;
	t_bool keep;
}	t_element;

typedef struct s_stack {
	t_element *first;
	int type;
} t_stack;

typedef struct s_control {
	t_stack	*a;
	t_stack *b;
	t_stack	*a_cpy;
	t_element *temp;
	int	count;
	int	action_nb;
	int index_push;
	int index_nb;
	int	s2_markup_head;
	int group_count;
	int group_size;
} t_control;

/* prototypes */
void		error(t_control *list);
void 		check_arg_errors(char *arg);
void		add_beg_list(t_stack *x, int numb);
void		add_end_list(t_stack *x, int numb);
void		push_b(t_control *list);
int			swap_x(t_stack *x);
t_bool		is_in_stack(t_stack *x, t_element *to_check);
t_bool		is_doublon(t_stack *a);
t_bool		is_sorted(t_stack *x);
void		two_elems(t_control *list);
void		three_elems(t_control *list, int first, int second, int third);
void		sort(t_control *list);
int			rotate_x(t_stack *x);
int			reverse_rotate_x(t_stack *x);
void		display_list(t_stack *x, char z);
void		push_a(t_control *list);
void		displayer(t_control *list);
t_bool		is_biggest(t_stack *x, int nb);
int 		compute_stack_size(t_stack *x);
t_element	*last_stack_elem(t_stack *x);
void		put_index(t_stack *x);
t_bool		is_smallest(t_stack *x, int nb);
void		large_stack_strat(t_control *list);
void		copy_stack(t_control *list);
void		affect_copy_index(t_stack *cpy_a);
void		affect_target_index(t_control *list);
void		init_values(t_stack *a);
void		add_full_elem_beg_list(t_stack *from, t_stack *to);
long		push_swap_atoi(const char *str, t_control *list);
int			find_smallest_nb(t_stack *x, int *pos);
int			strat2(t_control *list);
void		free_stack(t_stack *x);
int			find_index(t_stack *x, int index);
t_control	*init(void);
void 		free_all(t_control *list);
t_element 	*find_min_elem(t_stack *x);
t_element 	*find_max_elem(t_stack *x);
t_element 	*find_elem_of_index(t_stack *x, int index);
int 		find_keep_nb_str2(int index, t_stack *a, t_bool affect, int i);
int			strat1(t_control *list);
int			find_keep_nb(int index, t_stack *a, t_bool affect);
int			ft_max(int a, int b);
void		push_to_b_groups(t_control *list, int index_count);
int			push_to_top(t_stack *x, t_element *elem);
t_element	*find_just_after(t_stack *x, t_element *elem);
void		put_action_count(t_stack *x);
int			find_action_index(t_stack *x, int index);
void		sort_insertion(t_stack *a_cpy);
void		consolid_action_count(t_control *list);
t_element	*find_lower_action(t_stack *x);
int			move_1(t_element *min, t_element *max, t_element *temp, t_control *list);

#endif
