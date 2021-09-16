/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_groups.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:45:32 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/14 17:45:33 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

s_element	*best_group_elem(s_stack *x, int cur_group, int group_size)
{
	s_element	*temp;
	s_element	*good;
	int			distance;
	int			cur_dist;

	distance = 9999;
	temp = x->first;
	cur_dist = 0;
	good = NULL;
	if (x->first == NULL)
		return (NULL);
	if (x->first->next_one == NULL)
		return (x->first);
	while (temp != NULL)
	{
		if (temp->index < (group_size * cur_group) && !temp->keep)
		{
			cur_dist = find_index(x, temp->index);
			if (cur_dist < distance)
			{
				distance = cur_dist;
				good = temp;
			}
			if (distance == 1)
				break ;
		}
		temp = temp->next_one;
	}
	return (good);
}

void	push_to_b_groups(s_control *list, int index_count)
{
	int			size_list;
	int			cur_group;
	s_element	*temp;

	cur_group = 1;
	size_list = list->count;
	while (size_list > index_count && cur_group <= (list->group_count + 1))
	{
		temp = best_group_elem(list->a, cur_group, list->group_size);
		if (temp == NULL && ++cur_group)
			continue ;
		if (temp)
		{
			list->action_nb += push_to_top(list->a, temp);
			push_b(list);
			size_list--;
		}
	}
}
