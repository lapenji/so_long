/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:24:46 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 14:26:35 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_program *prg)
{
	if (prg->map[(prg->sp.y / TS) - 1][(prg->sp.x / TS)] == 'E' && prg->cc == 0)
		prg->win = 1;
	if (prg->map[(prg->sp.y / TS) - 1][(prg->sp.x / TS)] == 'C')
		prg->map[(prg->sp.y / TS) - 1][(prg->sp.x / TS)] = '0';
	prg->sp.y -= TS;
	prg->moves += 1;
	ft_printf("mossa numero -> %d \n", prg->moves);
}

void	go_down(t_program *prg)
{
	if (prg->map[(prg->sp.y / TS) + 1][(prg->sp.x / TS)] == 'E' && prg->cc == 0)
		prg->win = 1;
	if (prg->map[(prg->sp.y / TS) + 1][(prg->sp.x / TS)] == 'C')
		prg->map[(prg->sp.y / TS) + 1][(prg->sp.x / TS)] = '0';
	prg->sp.y += TS;
	prg->moves += 1;
	ft_printf("mossa numero -> %d \n", prg->moves);
}

void	go_left(t_program *prg)
{
	if (prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) - 1] == 'E' && prg->cc == 0)
		prg->win = 1;
	if (prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) - 1] == 'C')
		prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) - 1] = '0';
	prg->sp.x -= TS;
	prg->moves += 1;
	ft_printf("mossa numero -> %d \n", prg->moves);
}

void	go_right(t_program *prg)
{
	if (prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) + 1] == 'E' && prg->cc == 0)
		prg->win = 1;
	if (prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) + 1] == 'C')
		prg->map[(prg->sp.y / TS)][(prg->sp.x / TS) + 1] = '0';
	prg->sp.x += TS;
	prg->moves += 1;
	ft_printf("mossa numero -> %d \n", prg->moves);
}

int	check_map_square(t_program *dt)
{
	int	i;

	i = 0;
	while (dt->map[i] != 0)
	{
		if (ft_strlen(dt->map[i]) != ft_strlen(dt->map[0]))
			return (1);
		i++;
	}
	return (0);
}
