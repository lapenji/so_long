/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:24:34 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 17:23:14 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_toprint	*ft_initialise_toprint(t_toprint *tab)
{
	tab->wdt = 0;
	tab->zero = 0;
	tab->sign = 0;
	tab->dash = 0;
	tab->space = 0;
	tab->count = 0;
	tab->pos = 0;
	tab->minus = 0;
	tab->point = 0;
	tab->hasflags = 0;
	tab->prec = 0;
	tab->d = 0;
	return (tab);
}

t_toprint	*ft_reset_toprint(t_toprint *tab)
{
	tab->wdt = 0;
	tab->zero = 0;
	tab->sign = 0;
	tab->dash = 0;
	tab->space = 0;
	tab->minus = 0;
	tab->point = 0;
	tab->hasflags = 0;
	tab->prec = 0;
	tab->d = 0;
	return (tab);
}

t_toprint	*ftx_hexnb(const char *s, t_toprint *tab)
{
	int		tmp;
	int		lunghezza;

	tmp = va_arg(tab->list, int);
	lunghezza = count_unsigned(tmp, 16);
	if (tab->point == 1)
		tab->wdt -= tab->prec;
	if (tab->point == 1 && tmp == 0 && tab->wdt != 0 && tab->prec < lunghezza)
		lunghezza = 0;
	if (tab->minus == 0)
		writeflags(tab, lunghezza, 'h');
	ft_write_prec(tab, lunghezza);
	if (tab->dash == 1 && tmp != 0)
		tab->count += ft_writezerox(s[tab->pos]);
	if (!(tab->point == 1 && tmp == 0 && tab->prec == 0))
		tab->count += ft_puthex(tmp, s[tab->pos]);
	if (tab->point == 1 && tmp == 0 && tab->wdt != 0 && tab->prec == 0)
		tab->wdt ++;
	if (tab->minus == 1)
		writeflags(tab, lunghezza, 'h');
	return (tab);
}
