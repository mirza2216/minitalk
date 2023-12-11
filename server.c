/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirza <samirza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:53:32 by samirza           #+#    #+#             */
/*   Updated: 2023/12/11 21:22:15 by samirza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	rcv_msg(int bool)
{
	static char	c;
	static int	i;

	c = c | (bool == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	ft_printf("Server PID = %d\n", getpid());
	signal(SIGUSR1, rcv_msg);
	signal(SIGUSR2, rcv_msg);
	while (1)
	{
		pause();
	}
	return (0);
}
