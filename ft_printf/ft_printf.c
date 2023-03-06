/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:05:12 by rkhinchi          #+#    #+#             */
/*   Updated: 2022/11/14 15:56:41 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(va_list print, int i)
{
	int	result;

	result = 0;
	if (i == 'c')
		result = character_c(va_arg(print, int));
	else if (i == 'i' || i == 'd')
		result = integer_i_d(va_arg(print, int));
	else if (i == 'x' || i == 'X')
		result = hexadecimal_x(va_arg(print, unsigned int), i);
	else if (i == 'p')
		result = hexadecimal_p(va_arg(print, unsigned long long));
	else if (i == 's')
		result = string_s(va_arg(print, char *));
	else if (i == 'u')
		result = unsigned_integer_u(va_arg(print, unsigned int));
	else if (i == '%')
	{
		result = write(1, "%", 1);
	}
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	print;
	int		i;
	char	*s;
	int		c;

	s = (char *)str;
	c = 0;
	i = 0;
	va_start(print, str);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			c += check(print, s[i]);
		}
		else
		{
			c++;
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(print);
	return (c);
}

/*int	main(void)
{
	ft_printf(" %p ", -1);
	ft_printf(" %p ", 1);
	ft_printf(" %p ", 15);
	ft_printf(" %p ", 16);
	ft_printf(" %p ", 17);
	ft_printf(" %p %p ", 0, 0);
}*/
