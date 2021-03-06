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

t_element	*best_group_elem(t_stack *x, int cur_group, int group_size)
{
	t_element	*temp;
	t_element	*good;
	int			distance;
	int			cur_dist;

	distance = 9999;
	temp = x->first;
	good = NULL;
	if ((x->first == NULL) || (x->first->next_one == NULL))
		return (NULL);
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
		}
		temp = temp->next_one;
	}
	return (good);
}

void	push_to_b_groups(t_control *list, int index_count)
{
	int			size_list;
	int			cur_group;
	t_element	*temp;

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
