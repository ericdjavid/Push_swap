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

typedef enum s_bool {
	FALSE,
	TRUE
} t_bool;

/* for each number of the list will be created a t_number struct
 * greater than is a flag for each number that is greater than the previous ones
 * index is a classification of numbers, from the smallest to the biggest
 */
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

#endif
