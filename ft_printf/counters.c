/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:06 by ltombell          #+#    #+#             */
/*   Updated: 2022/10/14 14:41:15 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_nbr(long n, int base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= base)
	{
		n /= base;
		count++;
	}
	count++;
	return (count);
}

int	count_unsigned(unsigned int n, unsigned int base)
{
	unsigned int	count;

	count = 0;
	while (n >= base)
	{
		n /= base;
		count++;
	}
	count++;
	return (count);
}

int	count_ptr(uintptr_t num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (5);
	while (num >= 16)
	{
		count++;
		num /= 16;
	}
	count++;
	return (count + 2);
}

t_toprint	*ft_count_numb(const char *s, t_toprint *tab, char c)
{
	int		start;
	int		end;
	int		wdttemp;
	char	*flags;

	if (s[tab->pos] == ' ' || s[tab->pos] == '0')
		tab->pos++;
	start = tab->pos;
	while (s[tab->pos] >= '0' && s[tab->pos] <= '9')
		tab->pos++;
	end = tab->pos;
	flags = ft_substr(s, start, end - start);
	if (!flags)
		return (NULL);
	wdttemp = ft_atoi(flags);
	free(flags);
	if (c == 'p')
		tab->prec = wdttemp;
	else
		tab->wdt = wdttemp;
	return (tab);
}
