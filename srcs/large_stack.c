/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:28:58 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/02 15:29:16 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void copy_stack(s_control *list)
{
	s_element *temp;

	temp = list->a->first;
	while (temp != NULL)
	{
		add_end_list(list->a_cpy, temp->number);
		temp = temp->next_one;
	}
}

void sort_insertion(s_stack *a_cpy)
{
	s_element *temp;
	s_element *temp2;
	int tempo;

	temp = a_cpy->first;
	temp2 = a_cpy->first;
	while (!is_sorted(a_cpy))
	{
		while (temp != NULL)
		{
			while (temp2->next_one != NULL && temp2->next_one->number <= temp->number)
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

void affect_copy_index(s_stack *cpy_a)
{
	s_element *temp;
	int index;

	index = 0;
	temp = cpy_a->first;
	while (temp != NULL)
	{
		temp->index = index;
		temp = temp->next_one;
		index++;
	}
}

void affect_target_index(s_control *list)
{
	s_element *temp;
	s_element *temp2;

	temp = list->a->first;
	temp2 = list->a_cpy->first;
	while (temp != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp2->number == temp->number)
			{
				temp->index = temp2->index;
				break;
			}
			temp2 = temp2->next_one;
		}
		temp2 = list->a_cpy->first;
		temp = temp->next_one;
	}
}

int find_index(s_stack *x, int index)
{
	s_element *temp;
	int pos;

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

int count_to_top(s_stack *x, s_element *elem)
{
	int pos;
	int pos2;

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
			return(pos - 1);
		return (pos);
	}
	else
	{
		pos2 = compute_stack_size(x) - pos + 2;
		if (x->type == 0)
			return(pos2 - 1);
		return (pos2);
	}
}

void put_action_count(s_stack *x)
{
	s_element *temp;

	temp = x->first;
	while (temp != NULL)
	{
		temp->count_for_sort = count_to_top(x, temp);
		temp = temp->next_one;
	}
}

int find_action_index(s_stack *x, int index)
{
	s_element *temp;

	temp = x->first;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (temp->count_for_sort);
		temp = temp->next_one;
	}
	return (0);
}

int push_to_top(s_stack *x, s_element *elem)
{
	int pos;
	int pos2;
	int	i;

	i = 0;
	if (x->first == elem)
		return (FAILURE);
	pos = find_index(x, elem->index);
	if (pos == 2)
	{
		rotate_x(x);
		return (SUCCESS);
	}
	if (((float)pos / (float)compute_stack_size(x)) <= 0.5)
	{
		while (pos-- > 1 && ++i)
			rotate_x(x);
		return (i);
	}
	else
	{
		pos2 = compute_stack_size(x) - pos + 1;
		while (pos2-- && ++i)
			reverse_rotate_x(x);
		return (i);
	}
}

s_element *find_lower_action(s_stack *x)
{
	s_element *temp;
	s_element *minimal;

	temp = x->first;
	minimal = temp;
	temp = temp->next_one;
	while (temp != NULL)
	{
		if (temp->count_for_sort < minimal->count_for_sort)
			minimal = temp;
		temp = temp->next_one;
	}
	return (minimal);
}

void consolid_action_count(s_control *list)
{
	s_element  *temp;
	s_element *min;
	s_element *max;

	put_action_count(list->a);
	put_action_count(list->b);
	min = find_min_elem(list->a);
	max = find_max_elem(list->a);
	temp = list->b->first;

	while (temp != NULL)
	{
		if(temp->index < min->index)
			temp->count_for_sort += min->count_for_sort;
		else if(temp->index > max->index)
			temp->count_for_sort += max->count_for_sort;
		else if (find_index(list->a, (temp->index + 1)) != -1)
			temp->count_for_sort += find_action_index(list->a, temp->index + 1);
		else if (temp->index > min->index && temp->index < max->index && temp->index > last_stack_elem(list->a)->index
			&& temp->index < list->a->first->index)
			return;
		else if (temp->index > min->index && temp->index < max->index)
			temp->count_for_sort += find_just_after(list->a, temp)->count_for_sort;
		else
			temp->count_for_sort = 666666;
		temp = temp->next_one;
	}
}

void make_moves(s_control *list)
{
	s_element *min;
	s_element *max;
	s_element *temp;

	while (compute_stack_size(list->b))
	{
		min = find_min_elem(list->a);
		max = find_max_elem(list->a);
		consolid_action_count(list);
		temp = find_lower_action(list->b);
		if (temp->index < min->index || temp->index > max->index )
		{
			list->action_nb += push_to_top(list->a, min);
			list->action_nb += push_to_top(list->b, temp);
			push_a(list);
			continue;
		}
		if (find_index(list->a, (temp->index + 1)) != -1)
		{
			list->action_nb += push_to_top(list->a, find_elem_of_index(list->a, (temp->index + 1)));
			list->action_nb += push_to_top(list->b, temp);
			push_a(list);
			continue;
		}
		if (temp->index < max->index && temp->index > min->index && temp->index > last_stack_elem(list->a)->index
			&& temp->index < list->a->first->index)
		{
			push_to_top(list->b, temp);
			push_a(list);
			continue;
		}
		if (temp->index < max->index && temp->index > min->index)
		{
			push_to_top(list->a, find_just_after(list->a, temp));
			push_to_top(list->b, temp);
			push_a(list);
			continue;
		}
	}
}

void large_stack_strat(s_control *list)
{
	int s1;
	int s2;
	copy_stack(list);
	sort_insertion(list->a_cpy);
	affect_copy_index(list->a_cpy);
	affect_target_index(list);

	s1 = strat1(list);
	s2 = strat2(list);
	int index_count;
	if (s1 > s2)
	{
		find_keep_nb(list->s2_markup_head, list->a, TRUE);
		index_count = s1;
	}
	else
	{
		find_keep_nb_str2(list->s2_markup_head, list->a, TRUE);
		index_count = s2;
	}
	list->group_count = ft_max(1, (list->count) / 150.0);
	list->group_size = ((list->count) / list->group_count);
	push_to_b_groups(list, index_count);
	make_moves(list);
	if (!is_sorted(list->a))
		push_to_top(list->a, find_elem_of_index(list->a,0));
}