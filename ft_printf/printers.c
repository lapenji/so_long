/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:51:43 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 15:23:31 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
		ft_putchar("0123456789abcdef"[num]);
}

int	ft_put_ptr_txt(uintptr_t num)
{
	if (num == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		ft_putstr("0x");
		ft_put_ptr(num);
		return (count_ptr(num));
	}
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbru(unsigned int n)
{
	int	res;

	res = count_unsigned(n, 10);
	if (n > 9)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (res);
}
