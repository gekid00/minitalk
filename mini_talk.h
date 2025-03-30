/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:26:08 by gekido            #+#    #+#             */
/*   Updated: 2025/02/08 09:12:21 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <signal.h>
# include "./ft_printf/include/ft_printf.h"
# include <stdio.h>
# include <unistd.h>

# define BIT_COUNT 8 

void	signal_handler(int signum);
void	send_signal(int pid, char c);


#endif