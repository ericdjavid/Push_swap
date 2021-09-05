/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:56:31 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/31 13:56:32 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void push_b(s_control *list)
{
    s_element *temp;

    temp = list->a->first;
    list->a->first = list->a->first->next_one;
    if (list->b->first == NULL)
    {
        list->b->first = temp;
        temp->next_one = NULL;
		ft_putendl_fd("pb", 1);
		list->action_nb++;
        return;
    }
    temp->next_one = list->b->first;
    list->b->first = temp;
    ft_putendl_fd("pb", 1);
    list->action_nb++;
}


void push_a(s_control *list)
{
	s_element *temp;

	temp = list->b->first;
	if (list->b->first == NULL)
		return;
	list->b->first = list->b->first->next_one;
	if (list->a->first == NULL)
	{
		list->a->first = temp;
		temp->next_one = NULL;
		ft_putendl_fd("pa", 1);
		list->action_nb++;
		return;
	}
	temp->next_one = list->a->first;
	list->a->first = temp;
	ft_putendl_fd("pa", 1);
	list->action_nb++;
}

int    swap_x(s_stack *x)
{
    s_element *temp;
    int swap;

    if (x->first == NULL || x->first->next_one == NULL)
        return (0);
    temp = x->first->next_one;
    swap = temp->number;
    temp->number = x->first->number;
    x->first->number = swap;
    if (x->type == 0)
    	ft_putendl_fd("sa", 1);
    else
		ft_putendl_fd("sb", 1);
    return (1);
}

int 	rotate_x(s_stack *x)
{
	s_element *temp;
	int nb_temp;
	int index;
	s_bool keep;

	nb_temp = x->first->number;
	index = x->first->index;
	keep = x->first->keep;
	temp = x->first;
	while (temp->next_one != NULL)
	{
		temp->number = temp->next_one->number;
		temp->index = temp->next_one->index;
		temp->keep = temp->next_one->keep;
		temp = temp->next_one;
	}
	temp->number = nb_temp;
	temp->index = index;
	temp->keep = keep;
	if (x->type == 0)
		ft_putendl_fd("ra", 1);
	else
		ft_putendl_fd("rb", 1);
	return (1);
}

int reverse_rotate_x(s_stack *x)
{
	s_element *temp;
	int i;

	i = 1;
	if (x->first == NULL || x->first->next_one == NULL)
		return (0);
	temp = x->first;
	while (temp->next_one != NULL)
	{
		temp = temp->next_one;
		i++;
	}
	temp = x->first;
	while (i > 2)
	{
		temp = temp->next_one;
		i--;
	}
	add_beg_list(x, temp->next_one->number);
	free(temp->next_one);
	temp->next_one = NULL;
	if (x->type == 0)
		ft_putendl_fd("rra", 1);
	else
		ft_putendl_fd("rrb", 1);
	return (1);
}