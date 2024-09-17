/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:10:14 by baiannon          #+#    #+#             */
/*   Updated: 2024/09/17 15:20:21 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW	"\e[1;93m"
# define RESET	"\e[0m"

typedef struct s_bits_build
{
	char		octet;
	int			i;
}				t_bits_build;

#endif