/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:50:05 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/16 14:50:07 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_to_top(t_stack *x, t_element *elem)
{
	int	pos;
	int	pos2;

	pos = find_index(x, elem->index);
	if (pos == 2)
	{
		if (x->type == 0)
			return (1);
		return (2);
	}
	if (((float)pos / (float)compute_stack_size(x)) <= 0.5)
	{
		if (x->type == 0)
			return (pos - 1);
		return (pos);
	}
	else
	{
		pos2 = compute_stack_size(x) - pos + 2;
		if (x->type == 0)
			return (pos2 - 1);
		return (pos2);
	}
}

void	put_action_count(t_stack *x)
{
	t_element	*temp;

	temp = x->first;
	while (temp != NULL)
	{
		temp->count_for_sort = count_to_top(x, temp);
		temp = temp->next_one;
	}
}

int	find_action_index(t_stack *x, int index)
{
	t_element *temp;

	temp = x->first;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (temp->count_for_sort);
		temp = temp->next_one;
	}
	return (0);
}
