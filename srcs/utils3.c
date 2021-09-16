/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:43:17 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/16 14:43:18 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_beg_list(t_stack *x, int numb)
{
	t_element	*temp;

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

void	add_full_elem_beg_list(t_stack *from, t_stack *to)
{
	t_element	*temp;

	temp = malloc(sizeof(*temp));
	temp->number = from->first->number;
	temp->keep = from->first->keep;
	temp->index = from->first->index;
	if (!to->first)
	{
		temp->next_one = NULL;
		to->first = temp;
		return ;
	}
	temp->next_one = to->first;
	to->first = temp;
}

void	add_end_list(t_stack *x, int numb)
{
	t_element	*temp;
	t_element	*temp2;

	temp = malloc(sizeof(*temp));
	temp->number = numb;
	temp->index = -1;
	temp->count_for_sort = 0;
	if (!x->first)
	{
		temp->next_one = NULL;
		x->first = temp;
		return ;
	}
	temp2 = x->first;
	while (temp2->next_one)
		temp2 = temp2->next_one;
	temp2->next_one = temp;
	temp->next_one = NULL;
}

t_bool	is_sorted(t_stack *x)
{
	t_element	*temp;

	if (x->first == NULL || x->first->next_one == NULL)
		return (TRUE);
	temp = x->first;
	if (temp->number < temp->next_one->number && compute_stack_size(x) == 2)
		return (TRUE);
	if (compute_stack_size(x) == 3
		&& temp->next_one->next_one != NULL
		&& temp->number < temp->next_one->number
		&& temp->next_one->number < temp->next_one->next_one->number)
		return (TRUE);
	while (temp->next_one != NULL)
	{
		if (temp->next_one->number < temp->number)
			return (FALSE);
		temp = temp ->next_one;
	}
	return (TRUE);
}

void	display_list(t_stack *x, char z)
{
	t_element	*temp;

	temp = x->first;
	printf("--- Stack %c ---\n", z);
	if (temp == NULL)
	{
		printf("stack %c is empty\n", z);
		return ;
	}
	while (temp != NULL)
	{
		printf("%d [index : %d] [count_act : %d] [keep : %d]\n",
			   temp->number, temp->index, temp->count_for_sort, temp->keep);
		temp = temp->next_one;
	}
}
