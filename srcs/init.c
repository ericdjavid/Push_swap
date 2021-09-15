/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 00:18:28 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/08 00:18:29 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

s_control	*init()
{
	s_control	*list;
	s_stack	*a;
	s_stack	*b;
	s_stack *a_cpy;

	list = malloc(sizeof(*list));
	a = malloc(sizeof(*a));
	b = malloc(sizeof(*b));
	a_cpy = malloc(sizeof(*a_cpy));
	if (list == NULL || a == NULL || b == NULL || a_cpy == NULL)
		exit(EXIT_FAILURE);
	a->first = NULL;
	b->first = NULL;
	list->temp = NULL;
	a_cpy->first = NULL;
	list->count = 0;
	list->s2_markup_head = -1;
	list->action_nb = 0;
	list->a = a;
	list->b = b;
	list->a_cpy = a_cpy;
	list->a->type = 0;
	list->b->type = 1;
	list->index_nb = 0;
	list->index_push = 0;
	return(list);
}
