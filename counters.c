/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:28:47 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 17:39:24 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char **mappa)
{
	int	i;
	int	b;
	int	res;

	res = 0;
	i = 0;
	while (mappa[i] != NULL)
	{
		b = 0;
		while (mappa[i][b])
		{
			if (mappa[i][b] == 'C')
				res++;
			b++;
		}
		i++;
	}
	return (res);
}

int	count_base(char **mappa)
{
	int	i;

	i = 0;
	while (mappa[0][i] != '\n')
		i++;
	return (i);
}

int	count_height(char **mappa)
{
	int	i;

	i = 0;
	while (mappa[i] != 0)
	{
		i++;
	}
	return (i - 1);
}
