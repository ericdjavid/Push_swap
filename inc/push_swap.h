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
	struct t_element *next_one;
}	s_element;

typedef struct t_stack {
	s_element *first;
}	s_stack;

typedef struct s_control {

	s_stack	*a;
	s_stack *b;
	int 		count;

} s_control;

/* prototypes */
void 	error();
void 	check_arg_errors(char *arg);
void	add_beg_list(s_stack *x, int numb);
void	add_end_list(s_stack *x, int numb);
void	push_b(s_control *list);
void    swap_x(s_stack *x);
s_bool	is_in_stack(s_stack *x, s_element *to_check);
s_bool	is_doublon(s_stack *a);

#endif
