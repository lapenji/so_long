/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:46 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 16:53:32 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*writeflags(t_toprint *tab, int num, char t)
{
	int		i;
	char	c;

	i = 0;
	if ((tab->zero == 1) && tab->minus == 0)
		c = '0';
	else
		c = ' ';
	if (tab->point == 1 && t != 's')
	{
		num -= tab->prec;
		if (num < 0)
			num = 0;
	}
	while (i < (tab->wdt - num))
	{
		tab->count += ft_putchar(c);
		i++;
	}
	return (tab);
}

static t_toprint	*getflags(const char *s, t_toprint *tab)
{
	char	c;

	c = 'w';
	while (checkdoubles(s[tab->pos], "0 -+.#") == 1)
	{
		if (s[tab->pos] == '0')
			tab->zero = 1;
		else if (s[tab->pos] == ' ')
			tab->space = 1;
		else if (s[tab->pos] == '-')
			tab->minus = 1;
		else if (s[tab->pos] == '+')
			tab->sign = 1;
		else if (s[tab->pos] == '.')
		{
			tab->point = 1;
			c = 'p';
		}
		else if (s[tab->pos] == '#')
			tab->dash = 1;
		tab->pos++;
	}
	ft_count_numb(s, tab, c);
	return (tab);
}

t_toprint	*checkflags(const char *s, t_toprint *tab)
{
	getflags(s, tab);
	if (s[tab->pos] == '.')
	{
		tab->point = 1;
		tab->pos++;
		ft_count_numb(s, tab, 'p');
	}
	tab->hasflags = 1;
	if (tab->zero == 1 && tab->point == 1)
		tab->zero = 0;
	return (tab);
}

void	ft_write_prec(t_toprint *tab, int howlong)
{
	int		i;

	i = 0;
	while (i < tab->prec - howlong)
	{
		tab->count += ft_putchar('0');
		i++;
	}
}

t_toprint	*checknprint(const char *s, t_toprint *tab)
{
	if (s[tab->pos] == 'd' || s[tab->pos] == 'i')
		ftx_d(tab);
	if (s[tab->pos] == 'u')
		ftx_u(tab);
	if (s[tab->pos] == 's')
		ftx_str(tab);
	if (s[tab->pos] == 'c' || s[tab->pos] == '%')
		ftx_chars(s, tab);
	if (s[tab->pos] == 'x' || s[tab->pos] == 'X')
		ftx_hexnb(s, tab);
	if (s[tab->pos] == 'p')
		ftx_ptr(tab);
	tab->hasflags = 0;
	tab->pos++;
	ft_reset_toprint(tab);
	return (tab);
}
