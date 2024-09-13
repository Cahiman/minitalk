/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:10:51 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/13 20:29:21 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_data_signal
{
	char	byte;
	int		i;
}	t_data_signal;

void	ft_get_pid(void)
{
    pid_t pid;

    pid = getpid();
    ft_printf("The PID is: %d\n", pid);
}

void	rebuild_msg(int bit, siginfo_t *info, void *context)
{
	(void)context;
	
}

int main(void)
{
	ft_get_pid();
    while(1)
		pause();
    return 0;
}