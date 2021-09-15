/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:44:07 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/22 17:44:11 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(s_control *list)
{
	ft_putendl_fd("Error", 2);
	free_all(list);
	exit (EXIT_FAILURE);
}

s_bool	is_doublon(s_stack *a)
{
	s_element *temp;

	if (a->first == NULL)
		return TRUE;
	temp = a->first;
	while (temp->next_one != NULL)
	{
		if (is_in_stack(a, temp))
		{
			return (TRUE);
		}
		temp = temp->next_one;
	}
	return(FALSE);
}

s_bool	is_in_stack(s_stack *x, s_element *to_check)
{
	int i;
	s_element *temp;

	i = to_check->number;
	temp = x->first;
	while (temp->next_one != NULL)
	{
		temp = temp->next_one;
		if ((temp != to_check) && (i == temp->number))
		{
			return (TRUE);
		}
	}
	return(FALSE);
}