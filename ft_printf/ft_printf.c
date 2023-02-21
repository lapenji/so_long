/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:57:45 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/07 16:21:11 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	chiuditutto(t_toprint *tab)
{
	int	tmp;

	tmp = tab->count;
	free(tab);
	return (tmp);
}

int	ft_printf(const char *s, ...)
{
	t_toprint	*ciccio;

	ciccio = (t_toprint *)malloc(sizeof(t_toprint));
	if (!ciccio)
		return (0);
	ft_initialise_toprint(ciccio);
	va_start(ciccio->list, s);
	while (s[ciccio->pos] != '\0')
	{
		while (s[ciccio->pos] != '%' && ciccio->hasflags == 0 && s[ciccio->pos])
			writenormalchar(s, ciccio);
		if (s[ciccio->pos] == '%')
		{
			ciccio->pos++;
			if (s[ciccio->pos] == '\0')
				return (0);
			checkflags(s, ciccio);
			if (s[ciccio->pos] == '\0')
				return (0);
			checknprint(s, ciccio);
		}
	}
	va_end(ciccio->list);
	return (chiuditutto(ciccio));
}
