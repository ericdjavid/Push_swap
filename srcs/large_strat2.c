/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_strat2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:43:33 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/07 23:43:33 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_keep_nb_str2(int index, t_stack *a, t_bool affect, int i)
{
	t_element	*temp;
	int			count;
	int			comp;

	count = 0;
	temp = find_elem_of_index(a, index);
	if (affect == TRUE)
		temp->keep = TRUE;
	comp = temp->number;
	while (i--)
	{
		if (temp->next_one == NULL)
			temp = a->first;
		else
			temp = temp->next_one;
		if (comp < temp->number)
		{
			if (affect == TRUE)
				temp->keep = TRUE;
			comp = temp->number;
			count++;
		}
	}
	return (count);
}

int	strat2(t_control *list)
{
	int			nb_keep;
	t_element	*temp;
	int 		i;


	i = compute_stack_size(list->a) + 1;
	temp = list->a->first;
	nb_keep = 0;
	while (temp != NULL)
	{
		if (list->a->first->index == (list->a->first->next_one->index + 1))
		{
			swap_x(list->a);
			temp = list->a->first;
		}
		if (find_keep_nb_str2(temp->index, list->a, FALSE, i) > nb_keep)
		{
			nb_keep = find_keep_nb_str2(temp->index, list->a, FALSE, i);
			list->s2_markup_head = temp->index;
		}
		temp = temp->next_one;
	}
	return (nb_keep);
}
