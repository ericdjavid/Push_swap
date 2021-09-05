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

void 	two_elems(s_control *list)
{
	if (is_sorted(list->a))
		return;
	list->action_nb += swap_x(list->a);
}

void 	three_elems(s_control *list)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(list->a))
		return;
	first = list->a->first->number;
	second = list->a->first->next_one->number;
	third = list->a->first->next_one->next_one->number;
	if (first < second && second > third)
	{
		if (first < third)
		{
			list->action_nb += swap_x(list->a);
			list->action_nb += rotate_x(list->a);
		}
		if (first > third)
		{
			list->action_nb += reverse_rotate_x(list->a);
		}
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

void five_elems(s_control *list)
{
	int i;
	int	j;

	i = list->count;
	j = 1;
	if (is_sorted(list->a))
		return;
	while (i > 3)
	{
		push_b(list);
		i--;
	}
	three_elems(list);
	displayer(list);
	while (list->b->first != NULL)
	{
		i = 0;
		while (list->b->first->number > list->a->first->number)
		{
			//printf("\n%d is > %d\n", list->b->first->number, list->a->first->number);
			if (is_biggest(list->a, list->b->first->number) && is_biggest(list->b, list->b->first->number))
			{
				push_a(list);
				list->action_nb += rotate_x(list->a);
				break;
			}
			if (is_biggest(list->b, list->b->first->number))
			{
			//	printf("\nis biggest\n");
				while (last_stack_elem(list->a)->number > list->b->first->number)
				{
					j++;
					list->action_nb += reverse_rotate_x(list->a);
			//		printf("last eleme of a is %d",last_stack_elem(list->a)->number);
				}
				push_a(list);
				while (j > 0)
				{
					list->action_nb += rotate_x(list->a);
					j--;
				}
				break;
			}
			list->action_nb += rotate_x(list->a);
			i++;
		}
		push_a(list);
		while (i > 0)
		{
			list->action_nb += reverse_rotate_x(list->a);
			i--;
		}
		if (list->b->first == NULL)
			break;
	}
}

void 	sort(s_control *list)
{
	printf("\nlist count is %d", list->count);
//	while (!(is_sorted(list->a)))
//	{
		if (list->count == 2)
			two_elems(list);
		if (list->count == 3) //if list already ordered, do nothing ? Just verify
			three_elems(list);
		if (list->count > 3 && list->count < 6)
			five_elems(list);
		else
			large_stack_strat(list);
//	}
}