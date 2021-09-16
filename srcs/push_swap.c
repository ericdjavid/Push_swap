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

void	get_numbs(char *str, t_control *list)
{
	long	nb;
	t_bool	go;

	go = TRUE;
	while (*str)
	{
		if (*str != ' ' && go)
		{
			nb = push_swap_atoi(str, list);
			if (nb > 2147483647 || nb < -2147483648)
				error(list);
			add_end_list(list->a, nb);
			list->count++;
		}
		go = *str == ' ';
		str++;
	}
}

/* function that gets arguments and convert them into number */
void	convert_arg(char **argv, t_control *list)
{
	argv++;
	while (*argv)
	{
		get_numbs(*argv, list);
		argv++;
	}
	if (is_doublon(list->a))
		error(list);
	if (list->count == 1)
		exit (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_control	*list;

	if (argc == 1)
		exit(FAILURE);
	list = init();
	convert_arg(argv, list);
	init_values(list->a);
	if (is_sorted(list->a))
	{
		free_all(list);
		return (1);
	}
	sort(list);
	free_all(list);
	return (1);
}
