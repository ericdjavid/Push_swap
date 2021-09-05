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

typedef enum s_status {
	FAILURE,
	SUCCESS
} t_status;

typedef enum t_bool {
	FALSE,
	TRUE
} s_bool;

typedef struct t_element {
	int	number;
	int index;
	struct t_element *next_one;
	s_bool keep;
}	s_element;

typedef struct t_stack {
	s_element *first;
	int type;
}	s_stack;

typedef struct s_control {

	s_stack	*a;
	s_stack *b;
	s_stack	*a_cpy;
	int	count;
	int	action_nb;
	int index_push;
	int index_nb;

} s_control;

/* prototypes */
void 	error();
void 	check_arg_errors(char *arg);
void	add_beg_list(s_stack *x, int numb);
void	add_end_list(s_stack *x, int numb);
void	push_b(s_control *list);
int    swap_x(s_stack *x);
s_bool	is_in_stack(s_stack *x, s_element *to_check);
s_bool	is_doublon(s_stack *a);
s_bool	is_sorted(s_stack *x);
void 	two_elems(s_control *list);
void 	three_elems(s_control *list);
void 	sort(s_control *list);
int 	rotate_x(s_stack *x);
int reverse_rotate_x(s_stack *x);
void display_list(s_stack *x, char z);
void push_a(s_control *list);
void displayer(s_control *list);
s_bool	is_biggest(s_stack *x, int nb);
int compute_stack_size(s_stack *x);
s_element	*last_stack_elem(s_stack *x);
void put_index(s_stack *x);
s_bool	is_smallest(s_stack *x, int nb);
void large_stack_strat(s_control *list);
void copy_stack(s_control *list);
void affect_copy_index(s_stack *cpy_a);
void affect_target_index(s_control *list);
void affect_keep(s_stack *a);
void find_largest_keep(s_control *list);
int get_keep(s_element *temp);
void push_other_than_largest(s_control *list);
void init_values(s_stack *a);
void add_full_elem_beg_list(s_stack *from, s_stack *to);
void sort_b(s_control *list);
int	push_swap_atoi(const char *str);

#endif
