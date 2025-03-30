/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:15:35 by gekido            #+#    #+#             */
/*   Updated: 2025/02/08 10:13:17 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	signal_handler(int signum)
{
	static char		current_char = 0;
	static int		bit_count = 0;

	if (signum == SIGUSR1)
		current_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == BIT_COUNT)
	{
		write(1, &current_char, 1);
		current_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID du processus : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
