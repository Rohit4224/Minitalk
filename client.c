/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:59:28 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/06 17:03:10 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	g_server_ready = 1;

void	ft_received_bit(int signal)
{
	(void)signal;
	g_server_ready = 0;
}

void	bit_by_bit(int pid, char c)
{
	int	i;
	int	bit_value;

	signal(SIGUSR1, ft_received_bit);
	i = 7;
	while (i >= 0)
	{
		bit_value = (c >> i & 1);
		g_server_ready = 1;
		if (bit_value)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		while (g_server_ready)
			;
		i--;
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
	bit_by_bit(pid, 0);
}

void	actor(int signal)
{
	(void)signal;
	ft_printf("Message has been received! VOILA!!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3)
	{
		ft_printf ("Argument is invalid\n");
		exit (1);
	}
	signal(SIGUSR2, actor);
	pid = ft_atoi(argv[1]);
	pass_str(pid, argv[2]);
	while (1)
		pause();
}
