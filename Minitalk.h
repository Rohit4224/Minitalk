/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:34:18 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/05 19:14:58 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct recv
{
	unsigned char	c;
	int				bits;	
}	t_recv;

#endif