/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmusleh <abmusleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:24:44 by abmusleh          #+#    #+#             */
/*   Updated: 2026/01/22 12:49:25 by abmusleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr((n / 10));
		c = (n % 10) + '0';
		count += write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned((n / 10));
		c = (n % 10) + '0';
		count += write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}
// #include <limits.h>
// int main()
// {
// 	int x = ft_printf("%s", NULL);
// 	ft_printf("%d", x);
// 	int y = printf("%s", NULL);
// 	printf("%d", y);
// }