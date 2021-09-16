/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:46:39 by edjavid           #+#    #+#             */
/*   Updated: 2021/08/09 10:46:41 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	displayer(t_control *list)
{
	printf("\n");
	display_list(list->a, 'a');
	printf("\n");
	display_list(list->b, 'b');
}

t_bool	is_biggest(t_stack *x, int nb)
{
	t_element	*temp;

	temp = x->first;
	while (temp != NULL)
	{
		if (nb < temp->number)
			return (FALSE);
		temp = temp->next_one;
	}
	return (TRUE);
}

int	compute_stack_size(t_stack *x)
{
	t_element	*temp;
	int			count;

	temp = x->first;
	count = 0;
	if (x->first == NULL)
		return (0);
	while (temp->next_one != NULL)
	{
		count++;
		temp = temp->next_one;
	}
	return (++count);
}

t_element	*last_stack_elem(t_stack *x)
{
	t_element	*temp;

	if (x->first == NULL)
		return (NULL);
	temp = x->first;
	while (temp->next_one != NULL)
		temp = temp->next_one;
	return (temp);
}

t_element	*find_min_elem(t_stack *x)
{
	t_element	*temp;
	t_element	*min;

	if (x->first == NULL)
		return (NULL);
	if (x->first->next_one == NULL)
		return (x->first);
	min = x->first;
	temp = x->first->next_one;
	while (temp != NULL)
	{
		if (temp->index < min->index)
			min = temp;
		temp = temp->next_one;
	}
	return (min);
}

t_element	*find_max_elem(t_stack *x)
{
	t_element	*temp;
	t_element	*max;

	if (x->first == NULL)
		return (NULL);
	if (x->first->next_one == NULL)
		return (x->first);
	max = x->first;
	temp = x->first->next_one;
	while (temp != NULL)
	{
		if (temp->index > max->index)
			max = temp;
		temp = temp->next_one;
	}
	return (max);
}

t_element	*find_elem_of_index(t_stack *x, int index)
{
	t_element	*temp;

	if (x->first == NULL)
		return (NULL);
	temp = x->first;
	while (temp != NULL)
	{
		if (temp->index == index)
			return (temp);
		temp = temp->next_one;
	}
	return (NULL);
}

t_element	*find_just_after(t_stack *x, t_element *elem)
{
	t_element	*temp;
	int			idx;

	idx = 99999;
	temp = x->first;
	while (temp != NULL)
	{
		if (temp->index > elem->index)
			if (temp->index < idx)
				idx = temp->index;
		temp = temp->next_one;
	}
	return (find_elem_of_index(x, idx));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
