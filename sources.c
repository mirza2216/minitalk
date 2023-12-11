/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirza <samirza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:03:03 by samirza           #+#    #+#             */
/*   Updated: 2023/12/11 21:22:55 by samirza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned long long	ans;
	unsigned long long	max;
	int					sign;

	ans = 0;
	sign = 1;
	max = 9223372036854775807;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str && *str >= 48) && *str <= 57)
	{
		ans = ans * 10 + *str - '0';
		if (ans > max && sign == 1)
			return (-1);
		if (ans > max && sign == -1)
			return (0);
		str++;
	}
	return (ans * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	chk_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}
