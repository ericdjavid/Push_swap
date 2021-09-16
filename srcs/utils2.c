/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:42:40 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/16 14:42:41 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_index(t_stack *x)
{
	t_element	*temp;
	t_element	*temp2;

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

void	init_values(t_stack *a)
{
	t_element	*temp;

	temp = a->first;
	while (temp != NULL)
	{
		temp->index = 0;
		temp->keep = FALSE;
		temp = temp->next_one;
	}
}

long	push_swap_atoi(const char *str, t_control *list)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((*str < '0' || *str > '9')
		&& (*str != ' '))
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

t_bool	is_smallest(t_stack *x, int nb)
{
	t_element	*temp;

	temp = x->first;
	while (temp != NULL)
	{
		if (nb > temp->number)
			return (FALSE);
		temp = temp->next_one;
	}
	return (TRUE);
}

int		find_smallest_nb(t_stack *x, int *pos)
{
	t_element	*temp;

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
