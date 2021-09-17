/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:15:49 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/17 17:01:40 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_2(t_element *temp, t_control *list)
{
	list->action_nb += push_to_top(list->a,
			find_elem_of_index(list->a, (temp->index + 1)));
	list->action_nb += push_to_top(list->b, temp);
	push_a(list);
}

void 	move_4(t_element *temp, t_control *list)
{
	push_to_top(list->a, find_just_after(list->a, temp));
	push_to_top(list->b, temp);
	push_a(list);
}

void	make_moves(t_control *list, t_element *min, t_element *max,
				t_element *temp)
{
	while (compute_stack_size(list->b))
	{
		min = find_min_elem(list->a);
		max = find_max_elem(list->a);
		consolid_action_count(list);
		temp = find_lower_action(list->b);
		if(move_1(min, max, temp, list))
			continue ;
		if (find_index(list->a, (temp->index + 1)) != -1)
		{
			move_2(temp, list);
			continue ;
		}
		if (temp->index < max->index && temp->index > min->index
			&& temp->index > last_stack_elem(list->a)->index
			&& temp->index < list->a->first->index)
		{
			push_to_top(list->b, temp);
			push_a(list);
			continue ;
		}
		if (temp->index < max->index && temp->index > min->index)
		{
			move_4(temp, list);
			continue ;
		}
	}
}

void 	large_strack_strat2(t_control *list, int s1, int s2, int index_count)
{
	t_element	*min;
	t_element	*max;
	t_element	*temp;
	int			i;

	i = compute_stack_size(list->a) + 1;
	min = NULL;
	max = NULL;
	temp = NULL;
	if (s1 > s2)
	{
		find_keep_nb(list->s2_markup_head, list->a, TRUE);
		index_count = s1;
	}
	else
	{
		find_keep_nb_str2(list->s2_markup_head, list->a, TRUE, i);
		index_count = s2;
	}
	list->group_count = ft_max(1, (list->count) / 150.0);
	list->group_size = ((list->count) / list->group_count);
	push_to_b_groups(list, index_count);
	make_moves(list, min, max, temp);
	if (!is_sorted(list->a))
		push_to_top(list->a, find_elem_of_index(list->a, 0));
}

void	large_stack_strat(t_control *list)
{
	int	s1;
	int	s2;
	int	index_count;

	index_count = 0;
	copy_stack(list);
	sort_insertion(list->a_cpy);
	affect_copy_index(list->a_cpy);
	affect_target_index(list);
	s1 = strat1(list);
	s2 = strat2(list);
	large_strack_strat2(list, s1, s2, index_count);
}
