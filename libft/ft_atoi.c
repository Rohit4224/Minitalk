/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:20:29 by rkhinchi          #+#    #+#             */
/*   Updated: 2022/10/19 11:58:01 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str [i] == 32 || (str [i] >= 9 && str [i] <= 13))
	{
		i++;
	}
	if (str [i] == '-' || str[i] == '+')
	{
		if (str [i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str [i] >= '0' && str [i] <= '9')
	{
		result = result * 10 + str [i] - '0';
		i++;
	}
	return (result * sign);
}
