/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 23:14:33 by edjavid           #+#    #+#             */
/*   Updated: 2020/12/13 14:53:58 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void		ft_bzero(void *s, size_t n)
{
	char	*p;
	int		i;

	p = s;
	i = 0;
	while (n > 0)
	{
		p[i] = '\0';
		i++;
		n--;
	}
}
