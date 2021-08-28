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
		printf("%d\n", temp->number);
		temp = temp->next_one;
	}
}

s_control	*init()
{
	s_control	*list;
	s_stack	*a;
	s_stack	*b;

	list = malloc(sizeof(*list));
	a = malloc(sizeof(*a));
	b = malloc(sizeof(*b));
	if (list == NULL || a == NULL || b == NULL)
		exit(EXIT_FAILURE);
	a->first = NULL;
	b->first = NULL;
	list->count = 0;
	list->a = a;
	list->b = b;
	return(list);
}

void	get_numbs(char *str, s_control *list)
{
	int i;
	long nb;
	s_bool go;

	go = TRUE;
	i = 0;
	while (*str)
	{
		//TODO : if not number, can't work
		if(*str != ' ' && go)
		{
			nb = ft_atoi(str);
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
void convert_arg(char **argv, int argc, s_control *list)
{
	argv++;
	while (*argv)
	{
		//printf("|%s|\n", *argv);
		get_numbs(*argv, list);
		argv++;
	}
	if(is_doublon(list->a))
		error();
	//TODO: check doublons
}

int	main(int argc, char **argv)
{
	s_control	*list;

	if (argc == 1)
		exit(EXIT_FAILURE);
	list = init();
	convert_arg(argv, argc, list);
	display_list(list->a, 'a');
	printf("\n");
	display_list(list->b, 'b');
	push_b(list);
	printf("\n");
	swap_x(list->a);
	display_list(list->a, 'a');
	display_list(list->b, 'b');
	printf("\nNB d'arguments : %d\n", list->count);
	free_stack(list->a);
	free_stack(list->b);
	free(list->a);
	free(list->b);
	free(list);
	return (1);
}
