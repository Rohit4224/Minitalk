/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:38:14 by rkhinchi          #+#    #+#             */
/*   Updated: 2022/11/13 15:38:17 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointer(unsigned long long i)
{
	if (i >= 16)
	{
		pointer(i / 16);
		pointer(i % 16);
	}
	else if (i > 9)
	{
		character_c(i + 87);
	}
	else
		character_c(i + '0');
	return (i);
}

int	hexadecimal_p(unsigned long long i)
{
	unsigned int	c;

	c = 0;
	if (i == 0)
	{
		c += string_s("(nil)");
		return (c);
	}
	c += string_s("0x");
	pointer(i);
	while (i != 0)
	{
		c++;
		i = i / 16;
	}
	return (c);
}
