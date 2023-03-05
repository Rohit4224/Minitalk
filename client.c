/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:59:28 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/05 19:21:21 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	bit_by_bit(int pid, char c)
{
	int	i;
	int	bit_value;

	i = 7;
	bit_value = (c >> i & 1);
	while (i >= 0)
	{
		if (bit_value)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			usleep(50);
		}
	}
}

void	pass_str(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		bit_by_bit(pid, str[i]);
		i++;
	}
	bit_by_bit(pid, '\n');
	if (str[i] == '\0')
	{
		i = 0;
		while (i < 8)
		{
			kill(pid, SIGUSR1);
			return (0);
		}
		return (1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3 || ft_numeric(argv[1] == 0))
	{
		printf ("Argument is invalid");
		exit (1);
	}
	signal(SIGUSR1, actor);
	signal(SIGUSR2, actor);
	pid = ft_atoi(argv[1]);
	pass_str(pid, argv[2]);
	while (1)
		pause();
}
