/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:46:39 by edjavid           #+#    #+#             */
/*   Updated: 2021/08/09 10:46:41 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_beg_list(s_stack *x, int numb)
{
	s_element *temp;

	temp = malloc(sizeof(*temp));
	temp->number = numb;
	if (!x->first)
	{
		temp->next_one = NULL;
		x->first = temp;
		return ;
	}
	temp->next_one = x->first;
	x->first = temp;
}

void	add_end_list(s_stack *x, int numb)
{
	s_element *temp;
	s_element *temp2;

	temp = malloc(sizeof(*temp));
	temp->number = numb;
	if (!x->first)
	{
		temp->next_one = NULL;
		x->first = temp;
		return ;
	}
	temp2 = x->first;
	while(temp2->next_one)
		temp2 = temp2->next_one;
	temp2->next_one = temp;
	temp->next_one = NULL;
}
