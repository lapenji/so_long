/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:27 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 15:21:28 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	long	i;
	int		res;

	i = n;
	res = count_nbr(n, 10);
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
	return (res);
}

int	ft_puthex(int n, char flag)
{
	unsigned int	c;
	int				res;

	res = count_unsigned(n, 16);
	c = (unsigned int)n;
	if (c >= 16)
	{
		ft_puthex(c / 16, flag);
		ft_puthex(c % 16, flag);
	}
	else
	{
		if (flag == 'X')
			ft_putchar("0123456789ABCDEF"[c]);
		else if (flag == 'x')
			ft_putchar("0123456789abcdef"[c]);
	}
	return (res);
}

int	ft_writezerox(char c)
{
	if (c == 'x')
		return (ft_putstr("0x"));
	if (c == 'X')
		return (ft_putstr("0X"));
	return (0);
}

t_toprint	*ftx_str(t_toprint *tab)
{
	char	*str;

	tab->zero = 0;
	str = va_arg(tab->list, char *);
	if (!str)
		str = "(null)";
	if (tab->point == 1)
	{
		if ((ft_strcmp(str, "(null)") == 0) && tab->prec < 6)
			str = "";
		str = ft_substr(str, 0, tab->prec);
	}
	if (tab->minus == 0)
		writeflags(tab, ft_strlen(str), 's');
	tab->count += ft_putstr(str);
	if (tab->point == 1)
		free(str);
	if (tab->minus == 1)
		writeflags(tab, ft_strlen(str), 's');
	return (tab);
}

t_toprint	*writenormalchar(const char *s, t_toprint *tab)
{
	tab->count += write(1, &s[tab->pos], 1);
	tab->pos ++;
	return (tab);
}
