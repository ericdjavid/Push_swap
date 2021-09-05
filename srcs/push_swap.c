/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:32:13 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/13 11:37:58 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void free_stack(s_stack *x)
{
	s_element *elem;

	elem = x->first;
	while (elem)
	{
		x->first = x->first->next_one;
		free(elem);
		elem = x->first;
	}
}


s_control	*init()
{
	s_control	*list;
	s_stack	*a;
	s_stack	*b;
	s_stack *a_cpy;

	list = malloc(sizeof(*list));
	a = malloc(sizeof(*a));
	b = malloc(sizeof(*b));
	a_cpy = malloc(sizeof(*a_cpy));
	if (list == NULL || a == NULL || b == NULL || a_cpy == NULL)
		exit(EXIT_FAILURE);
	a->first = NULL;
	b->first = NULL;
	a_cpy->first = NULL;
	list->count = 0;
	list->action_nb = 0;
	list->a = a;
	list->b = b;
	list->a_cpy = a_cpy;
	list->a->type = 0;
	list->b->type = 1;
	list->index_nb = 0;
	list->index_push = 0;
	return(list);
}

void	get_numbs(char *str, s_control *list)
{
	long nb;
	s_bool go;

	go = TRUE;
	while (*str)
	{
		//TODO : if not number, can't work
		if(*str != ' ' && go)
		{
			nb = push_swap_atoi(str);
			if (nb > 2147483647 || nb < -2147483648)
				error();
			add_end_list(list->a, nb);
			list->count++;
		}
		go = *str == ' ';
		str++;
	}
}

/* function that gets arguments and convert them into number */
void convert_arg(char **argv, s_control *list)
{
	argv++;
	while (*argv)
	{
		get_numbs(*argv, list);
		argv++;
	}
	if(is_doublon(list->a))
		error();
	if(list->count == 1)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	s_control	*list;

	if (argc == 1)
		exit(EXIT_FAILURE);
	list = init();
	convert_arg(argv, list);
	init_values(list->a);
	sort(list);
	displayer(list);
	printf("action nb is %d", list->action_nb);
	free_stack(list->a);
	free_stack(list->b);
	free_stack(list->a_cpy);
	free(list->a);
	free(list->b);
	free(list->a_cpy);
	free(list);
	return (1);
}
