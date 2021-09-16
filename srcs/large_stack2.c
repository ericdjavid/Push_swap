/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:40:40 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/16 14:40:41 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	copy_stack(t_control *list)
{
	t_element	*temp;

	temp = list->a->first;
	while (temp != NULL)
	{
		add_end_list(list->a_cpy, temp->number);
		temp = temp->next_one;
	}
}

void	sort_insertion(t_stack *a_cpy)
{
	t_element	*temp;
	t_element	*temp2;
	int			tempo;

	temp = a_cpy->first;
	temp2 = a_cpy->first;
	while (!is_sorted(a_cpy))
	{
		while (temp != NULL)
		{
			while (temp2->next_one != NULL
				   && temp2->next_one->number <= temp->number)
				temp2 = temp2->next_one;
			tempo = temp2->number;
			temp2->number = temp->number;
			temp->number = tempo;
			temp2 = a_cpy->first;
			temp = temp->next_one;
		}
		temp = a_cpy->first;
	}
}

void	affect_copy_index(t_stack *cpy_a)
{
	t_element	*temp;
	int			index;

	index = 0;
	temp = cpy_a->first;
	while (temp != NULL)
	{
		temp->index = index;
		temp = temp->next_one;
		index++;
	}
}

void	affect_target_index(t_control *list)
{
	t_element	*temp;
	t_element	*temp2;

	temp = list->a->first;
	temp2 = list->a_cpy->first;
	while (temp != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp2->number == temp->number)
			{
				temp->index = temp2->index;
				break ;
			}
			temp2 = temp2->next_one;
		}
		temp2 = list->a_cpy->first;
		temp = temp->next_one;
	}
}

int	find_index(t_stack *x, int index)
{
	t_element	*temp;
	int			pos;

	pos = 0;
	temp = x->first;
	while (temp != NULL)
	{
		pos++;
		if (temp->index == index)
			return (pos);
		temp = temp->next_one;
	}
	return (-1);
}
