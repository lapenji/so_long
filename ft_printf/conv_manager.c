/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:45:13 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 17:23:19 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_toprint	*checknumb(t_toprint *tab, int tmp)
{
	if (tab->space == 1 && tmp >= 0 && tab->wdt == 0)
		tab->wdt = count_nbr(tmp, 10) + 1;
	if (tab->point == 1)
		tab->wdt -= tab->prec;
	if (tab->point == 1 && tmp < 0 && tab->prec < count_nbr(tmp, 10))
		tab->wdt++;
	if (tmp < 0 && tab->point == 1)
		tab->wdt --;
	if (tab->point == 1 && tmp == 0 && tab->wdt != 0 && tab->prec < tab->d)
		tab->d = 0;
	if (tab->tmpd < 0 && tab->zero == 1)
	{
		tab->count += ft_putchar('-');
		tab->tmpd *= -1;
	}
	return (tab);
}

t_toprint	*ftx_d(t_toprint *tab)
{
	tab->tmpd = va_arg(tab->list, int);
	tab->d = count_nbr(tab->tmpd, 10);
	checknumb(tab, tab->tmpd);
	if (tab->minus == 0)
		writeflags(tab, tab->d, 'd');
	if (tab->tmpd < 0 && tab->point == 1)
	{
		tab->count += ft_putchar('-');
		tab->tmpd *= -1;
		tab->d --;
	}
	if (tab->tmpd >= 0 && tab->sign == 1)
		tab->count += ft_putchar('+');
	ft_write_prec(tab, tab->d);
	if (!(tab->point == 1 && tab->tmpd == 0 && tab->prec == 0))
		tab->count += ft_putnbr(tab->tmpd);
	if (tab->minus == 1)
		writeflags(tab, tab->d, 'd');
	return (tab);
}

t_toprint	*ftx_u(t_toprint *tab)
{
	unsigned int	tmp;
	int				lunghezza;

	tmp = va_arg(tab->list, unsigned int);
	lunghezza = count_unsigned(tmp, 10);
	if (tab->point == 1)
		tab->wdt -= tab->prec;
	if (tab->point == 1 && tmp == 0 && tab->wdt != 0 && tab->prec < lunghezza)
		lunghezza = 0;
	if (tab->minus == 0)
		writeflags(tab, lunghezza, 'n');
	ft_write_prec(tab, lunghezza);
	if (!(tab->point == 1 && tmp == 0 && tab->prec == 0))
		tab->count += ft_putnbru(tmp);
	if (tab->point == 1 && tmp == 0 && tab->wdt != 0 && tab->prec == 0)
		tab->wdt ++;
	if (tab->minus == 1)
		writeflags(tab, lunghezza, 'n');
	return (tab);
}

t_toprint	*ftx_ptr(t_toprint *tab)
{
	uintptr_t	p;
	int			lunghezza;

	p = va_arg(tab->list, uintptr_t);
	if (tab->sign == 1)
		tab->count += ft_putchar('+');
	lunghezza = count_ptr(p);
	if (tab->minus == 0)
		writeflags(tab, lunghezza, 'p');
	tab->count += ft_put_ptr_txt(p);
	if (tab->minus == 1)
		writeflags(tab, lunghezza, 'p');
	return (tab);
}

t_toprint	*ftx_chars(const char *s, t_toprint *tab)
{
	int		ch;

	if (s[tab->pos] == 'c')
	{
		ch = va_arg(tab->list, int);
		if (tab->minus == 0)
			writeflags(tab, 1, 'c');
		tab->count += ft_putchar(ch);
		if (tab->minus == 1)
			writeflags(tab, 1, 'c');
	}
	else if (s[tab->pos] == '%')
		tab->count += (ft_putchar('%'));
	return (tab);
}
