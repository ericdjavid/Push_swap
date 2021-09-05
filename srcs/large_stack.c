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

void affect_keep(s_stack *a)
{
	s_element *temp;
	int last_val;

	temp = a->first;
	while (temp->next_one != NULL)
	{
		if (temp->index == (temp->next_one->index - 1))
		{
			temp->keep = TRUE;
			temp->next_one->keep = TRUE;
			temp = temp->next_one;
		}
		else
			temp->keep = FALSE;
		last_val = temp->index;
		temp = temp->next_one;
	}
	if (temp->index == last_val + 1)
		temp->keep = TRUE;
}

int get_keep(s_element *temp)
{
	int i;

	i = 0;
	while (temp != NULL && temp->keep == TRUE)
	{
		i++;
		temp = temp->next_one;
	}
	return (i);
}

//un keep de plus à garder
void find_largest_keep(s_control *list)
{
	s_element *temp;
	int count;
	int index;
	int tempo;

	count = 0;
	temp = list->a->first;
	while (temp != NULL)
	{
		if (temp->keep == TRUE)
		{
			index = temp->index;
			if ((tempo = get_keep(temp)) > count)
			{
				list->index_push = index;
				count = tempo;
			}
		}
		temp = temp->next_one;
		list->index_nb = count;
	}
	printf("\n largest keep is index %d with %d true\n", list->index_push, count);
}

void push_other_than_largest(s_control *list)
{
	s_element *temp;
	int dimin;
	int i;

//	if (list->index_nb != 0)
		dimin = list->index_nb;
//	else
//		dimin = 3;
	i = list->count;
	temp = list->a->first;
	while (i - dimin > 0)
	{
		if (temp->index == list->index_push)
		{
			while (list->index_nb > 0)
			{
				list->action_nb += rotate_x(list->a);
				list->index_nb--;
			}
		}
		i--;
		push_b(list);
		temp = list->a->first;
	}
}

void sort_b(s_control *list)
{
	s_element *temp;

	if (list->a->first == NULL)
		push_a(list);
	while (list->b->first)
	{
		temp = list->b->first;
		if (temp->index == list->a->first->index - 1)
		{
			push_a(list);
			temp = list->b->first;
		}
		if (list->b->first && temp->index == last_stack_elem(list->a)->index + 1)
		{
			push_a(list);
			list->action_nb += rotate_x(list->a);
		}
		if (list->b->first)
			list->action_nb += rotate_x(list->b);
	}
}

void large_stack_strat(s_control *list)
{
	copy_stack(list);
	sort_insertion(list->a_cpy);
	affect_copy_index(list->a_cpy);
	affect_target_index(list);
	affect_keep(list->a);
	find_largest_keep(list);
	displayer(list);
	push_other_than_largest(list);
	sort_b(list);
	displayer(list);

}