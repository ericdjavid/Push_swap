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

int	push_to_top(t_stack *x, t_element *elem)
{
	int	pos;
	int	pos2;
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
	pos2 = compute_stack_size(x) - pos + 1;
	while (pos2-- && ++i)
		reverse_rotate_x(x);
	return (i);
}

t_element	*find_lower_action(t_stack *x)
{
	t_element	*temp;
	t_element	*minimal;

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

void	consolid_action2(t_element *temp, t_element *min,
	t_element *max, t_control *list)
{
	while (temp != NULL)
	{
		if (temp->index < min->index)
			temp->count_for_sort += min->count_for_sort;
		else if (temp->index > max->index)
			temp->count_for_sort += max->count_for_sort;
		else if (find_index(list->a, (temp->index + 1)) != -1)
			temp->count_for_sort += find_action_index(list->a, temp->index + 1);
		else if (temp->index > min->index && temp->index < max->index
			&& temp->index > last_stack_elem(list->a)->index
			&& temp->index < list->a->first->index)
			return ;
		else if (temp->index > min->index && temp->index < max->index)
			temp->count_for_sort += find_just_after(list->a,
					temp)->count_for_sort;
		else
			temp->count_for_sort = 666666;
		temp = temp->next_one;
	}
}

void	consolid_action_count(t_control *list)
{
	t_element	*temp;
	t_element	*min;
	t_element	*max;

	put_action_count(list->a);
	put_action_count(list->b);
	min = find_min_elem(list->a);
	max = find_max_elem(list->a);
	temp = list->b->first;
	consolid_action2(temp, min, max, list);
}

int	move_1(t_element *min, t_element *max, t_element *temp, t_control *list)
{
	if ((temp->index < min->index) || (temp->index > max->index))
	{
		list->action_nb += push_to_top(list->a, min);
		list->action_nb += push_to_top(list->b, temp);
		push_a(list);
		return (SUCCESS);
	}
	return (FAILURE);
}
