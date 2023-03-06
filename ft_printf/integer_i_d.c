/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:41:48 by rkhinchi          #+#    #+#             */
/*   Updated: 2022/11/13 15:42:10 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	result(long int i);

int	integer_i_d(long int i)
{
	int	t;

	result(i);
	t = 0;
	if (i == 0)
	{
		t = 1;
		return (t);
	}
	if (i < 0)
	{
		t++;
		i = -i;
	}
	while (i != 0)
	{
		i = i / 10;
		t++;
	}
	return (t);
}

static int	result(long int i)
{
	if (i > 9)
	{
		integer_i_d(i / 10);
		integer_i_d(i % 10);
	}
	else if (i < 0)
	{
		character_c('-');
		i = -i;
		integer_i_d(i);
	}
	else
	{
		character_c(i + '0');
	}
	return (i);
}
