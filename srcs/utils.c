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

void	add_beg_list(s_stack *x, int numb)
{
	s_element *temp;

	temp = malloc(sizeof(*temp));
	temp->number = numb;
	if (!x->first)
	{
		temp->next_one = NULL;
		x->first = temp;
		return ;
	}
	temp->next_one = x->first;
	x->first = temp;
}

void	add_full_elem_beg_list(s_stack *from, s_stack *to)
{
	s_element *temp;

	temp = malloc(sizeof(*temp));
	temp->number = from->first->number;
	temp->keep = from->first->keep;
	temp->index = from->first->index;
	if (!to->first)
	{
		temp->next_one = NULL;
		to->first = temp;
		return ;
	}
	temp->next_one = to->first;
	to->first = temp;
}

void	add_end_list(s_stack *x, int numb)
{
	s_element *temp;
	s_element *temp2;

	temp = malloc(sizeof(*temp));
	temp->number = numb;
	temp->index = -1;
	temp->count_for_sort = 0;
	if (!x->first)
	{
		temp->next_one = NULL;
		x->first = temp;
		return ;
	}
	temp2 = x->first;
	while(temp2->next_one)
		temp2 = temp2->next_one;
	temp2->next_one = temp;
	temp->next_one = NULL;
}

s_bool	is_sorted(s_stack *x)
{
	s_element *temp;

	if (x->first == NULL || x->first->next_one == NULL)
		return TRUE;
	temp = x->first;
	if (temp->number < temp->next_one->number && compute_stack_size(x) == 2)
		return TRUE;
	if (compute_stack_size(x) == 3 && temp->next_one->next_one != NULL && temp->number < temp->next_one->number
		&& temp->next_one->number < temp->next_one->next_one->number)
		return TRUE;
	while (temp->next_one != NULL)
	{
		if (temp->next_one->number < temp->number)
			return (FALSE);
		temp = temp ->next_one;
	}
	return (TRUE);
}

void display_list(s_stack *x, char z)
{
	s_element *temp;
	temp = x->first;
	printf("--- Stack %c ---\n", z);
	if (temp == NULL)
	{
		printf("stack %c is empty\n", z);
		return;
	}
	while (temp != NULL)
	{
		printf("%d [index : %d] [count_act : %d] [keep : %d]\n", temp->number, temp->index,  temp->count_for_sort, temp->keep);
		temp = temp->next_one;
	}
}

void displayer(s_control *list)
{
	printf("\n");
	display_list(list->a, 'a');
	printf("\n");
	display_list(list->b, 'b');
}

s_bool	is_biggest(s_stack *x, int nb)
{
	s_element *temp;

	temp = x->first;
	while (temp != NULL)
	{
			if (nb < temp->number)
				return FALSE;
			temp = temp->next_one;
	}
	return TRUE;
}

int compute_stack_size(s_stack *x)
{
	s_element *temp;
	int count;

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

s_element	*last_stack_elem(s_stack *x)
{
	s_element *temp;

	if (x->first == NULL)
		return (NULL);
	temp = x->first;
	while (temp->next_one != NULL)
		temp = temp->next_one;
	return (temp);
}

void put_index(s_stack *x)
{
	s_element *temp;
	s_element *temp2;

	temp = x->first;
	temp2 = x->first;
	while (temp->next_one != NULL)
	{
		while (temp2->next_one != NULL)
		{
			if (temp->number)
			temp2 = temp->next_one;
		}
		temp = temp->next_one;
	}
}

void init_values(s_stack *a)
{
	s_element *temp;

	temp = a->first;
	while (temp != NULL)
	{
		temp->index = 0;
		temp->keep = FALSE;
		temp = temp->next_one;
	}
}

long	push_swap_atoi(const char *str, s_control *list)
{
	long nb;
	int sign;

	nb = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((*str < '0' || *str > '9') &&
	(*str != ' '))
		error(list);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (*str - '0');
		str++;
	}
	if (*str && *str != ' ')
		error(list);
	return (nb * sign);
}

s_bool	is_smallest(s_stack *x, int nb)
{
	s_element *temp;

	temp = x->first;
	while (temp != NULL)
	{
		if (nb > temp->number)
			return FALSE;
		temp = temp->next_one;
	}
	return TRUE;
}

int 	find_smallest_nb(s_stack *x, int *pos)
{
	s_element *temp;

	if (x->first == NULL)
		return (FAILURE);
	temp = x->first;
	while (temp != NULL)
	{
		++*pos;
		if (is_smallest(x, temp->number))
			return (temp->number);
		temp = temp->next_one;
	}
	return (FAILURE);
}

s_element *find_min_elem(s_stack *x)
{
	s_element *temp;
	s_element *min;

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

s_element *find_max_elem(s_stack *x)
{
	s_element *temp;
	s_element *max;

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

s_element *find_elem_of_index(s_stack *x, int index)
{
	s_element *temp;

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

s_element *find_just_after(s_stack *x, s_element *elem)
{
	s_element *temp;
	int idx;

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
