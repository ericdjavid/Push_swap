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

    temp = malloc(sizeof(*temp));
    temp = list->a->first;
    list->a->first = list->a->first->next_one;
    if (list->b->first == NULL)
    {
        list->b->first = temp;
        temp->next_one = NULL;
        return;
    }
    temp->next_one = list->b->first;
    list->b->first = temp;
    free(temp); 
}

void    swap_x(s_stack *x)
{
    s_element *temp;
    int swap;

    if (x->first == NULL || x->first->next_one == NULL)
        return;
    swap = 0;    
    temp = malloc(sizeof(*temp));
    temp = x->first;
    while (temp->next_one != NULL)
        temp = temp->next_one;
    swap = temp->number;
    temp->number = x->first->number;
    x->first->number = swap; 
}