/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:11:01 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/18 16:13:22 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1))
			{
				ft_printf(RED "Error: Invalid PID!\n" RESET);
				exit(EXIT_FAILURE);
			}
		}
		else if (kill(pid, SIGUSR2))
		{
			ft_printf(RED "Error: Invalid PID!\n" RESET);
			exit(EXIT_FAILURE);
		}
		c >>= 1;
		usleep(1500);
	}
}

void	signal_confirmation(int signal)
{
	(void)signal;
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac != 3)
	{
		ft_printf(RED "Error: ./client <PID> [Message]\n" RESET);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, signal_confirmation);
	pid = ft_atoi(av[1]);
	while (av[2][i])
		send_bits(pid, av[2][i++]);
	send_bits(pid, 0);
	ft_printf(GREEN "Message received with success!\n" RESET);
	return (0);
}
