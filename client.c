/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirza <samirza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:55:53 by samirza           #+#    #+#             */
/*   Updated: 2023/12/11 21:24:19 by samirza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int c_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) != 0)
			kill(c_pid, SIGUSR1);
		else
			kill(c_pid, SIGUSR2);
		usleep (250);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	c_pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		if (chk_alpha(av[1]) == 1)
		{
			ft_printf("PID only has numbers\n");
			return (0);
		}
		c_pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			send_sig(c_pid, av[2][i]);
			i++;
		}
		send_sig(c_pid, '\n');
	}
	else
		ft_printf("3 arguments are must!");
	return (0);
}
