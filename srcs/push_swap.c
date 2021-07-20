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

#include <stdlib.h>
#include "../inc/push_swap.h"

void	error(char *reason)
{
	ft_putendl_fd(reason, 2);
	exit (1);
}


void	check_arg_errors(char *arg)
{
	//TODO add if > int
	while (*arg)
	{
	//	printf("*arg++ is %c\n", *arg);
		if((!ft_isdigit(*arg)) && (*arg != '-'))
			error("Error\nOne or more arg are not numbers.");
		*arg++;
	}
}

void get_param(int argc, char **arg)
{
	int		**int_array;
	char 	**char_array;


	if ((argc) < 2)
		error("invalid number of arguments");

	//int_array = malloc(sizeof(int) * (argc - 1));
	while (--argc > 0)
	{
		check_arg_errors(arg[argc]);
		ft_putnbr_fd(ft_atoi(arg[argc]), 1);
	}
	//TODO convert argument list into numbers
	//TODO if letter or characters spé, ko
	//TODO if > int
	//TODO if error, display "Error \n"
}

int	main(int argc, char **argv)
{
	get_param(argc, argv);
	//TODO CHECK ARGV
}