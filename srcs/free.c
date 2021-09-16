/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 00:10:54 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/08 00:10:56 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(s_stack *x)
{
	s_element	*elem;

	elem = x->first;
	while (elem)
	{
		x->first = x->first->next_one;
		free(elem);
		elem = x->first;
	}
}

void	free_all(s_control *list)
{
	free_stack(list->a);
	free_stack(list->b);
	free_stack(list->a_cpy);
	free(list->a);
	free(list->b);
	free(list->a_cpy);
	free(list);
}
