/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:10:51 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/18 15:57:55 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bits_build	g_bits_build = {0, 0};

void	ft_get_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf(YELLOW "The PID is: %d\n" RESET, pid);
}

void	rebuild_msg(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		sig = 1;
	else
		sig = 0;
	g_bits_build.octet |= sig << g_bits_build.i++;
	if (g_bits_build.i == 8)
	{
		g_bits_build.i = 0;
		if (g_bits_build.octet)
			ft_printf("%c", g_bits_build.octet);
		else
			ft_printf("\n");
		g_bits_build.octet = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	bit_0;
	struct sigaction	bit_1;

	bit_0.sa_flags = SA_SIGINFO;
	bit_1.sa_flags = SA_SIGINFO;
	bit_0.sa_sigaction = rebuild_msg;
	bit_1.sa_sigaction = rebuild_msg;
	ft_get_pid();
	sigaction(SIGUSR1, &bit_1, NULL);
	sigaction(SIGUSR2, &bit_0, NULL);
	while (1)
		pause();
	return (0);
}
