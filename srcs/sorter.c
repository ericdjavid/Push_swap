/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 18:29:16 by edjavid           #+#    #+#             */
/*   Updated: 2021/08/28 18:29:33 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	two_elems(t_control *list)
{
	if (is_sorted(list->a))
		return ;
	list->action_nb += swap_x(list->a);
}

void	three_elems(t_control *list, int first, int second, int third)
{
	if (is_sorted(list->a))
		return ;
	if (first < second && second > third)
	{
		if (first < third)
		{
			list->action_nb += swap_x(list->a);
			list->action_nb += rotate_x(list->a);
		}
		if (first > third)
			list->action_nb += reverse_rotate_x(list->a);
	}
	if (first > second && second < third)
	{
		if (first > third)
			list->action_nb += rotate_x(list->a);
		if (first < third)
			list->action_nb += swap_x(list->a);
	}
	if (first > second && second > third)
	{
		list->action_nb += swap_x(list->a);
		list->action_nb += reverse_rotate_x(list->a);
	}
}

void	five_elems(t_control *list)
{
	int	j;
	int	pos;

	pos = 0;
	if (is_sorted(list->a))
		return ;
	while (compute_stack_size(list->a) > 3)
	{
		j = find_smallest_nb(list->a, &pos);
		while (list->a->first->number != j)
		{
			if ((float)pos / ((float)list->count) < 0.5)
				rotate_x(list->a);
			else
				reverse_rotate_x(list->a);
		}
		push_b(list);
	}
	three_elems(list, list->a->first->number, list->a->first->next_one->number,
				list->a->first->next_one->next_one->number);
	while (compute_stack_size(list->b))
		push_a(list);
}

void	sort(t_control *list)
{
	if (list->count == 2)
		two_elems(list);
	if (list->count == 3)
		three_elems(list, list->a->first->number, list->a->first->next_one->number,
			  list->a->first->next_one->next_one->number);
	if ((list->count > 3) && (list->count < 6))
		five_elems(list);
	if (list->count >= 6)
		large_stack_strat(list);
}
