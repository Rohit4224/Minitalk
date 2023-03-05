/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:59:18 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/05 19:21:09 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

t_recv	g_recv;

void	actor(int sig_n, siginfo_t *info, void *cntxt)
{
	(void)cntxt;
	g_recv.c = 0;
	g_recv.bits = 0;
	if (sig_n == SIGUSR1)
		g_recv.c = (g_recv.c << 1) | 0;
	else if (sig_n == SIGUSR2)
		g_recv.c = (g_recv.c << 1) | 1;
	g_recv.bits++;
	if (g_recv.bits == 8)
	{
		if (g_recv.c)
			write(1, &g_recv.c, 1);
		g_recv.c = 0;
		g_recv.bits = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(1);
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = actor;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	printf("PID : %d\n", getpid());
	while (1)
		pause();
}
