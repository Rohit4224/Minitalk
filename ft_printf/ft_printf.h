/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:33 by rkhinchi          #+#    #+#             */
/*   Updated: 2022/11/11 15:22:01 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	character_c(int c);
int	integer_i_d(long int i);
int	hexadecimal_p(unsigned long long i);
int	hexadecimal_x(unsigned int i, int type);
int	string_s(char *c);
int	unsigned_integer_u(unsigned int i);
int	ft_printf(const char *str, ...);

#endif
