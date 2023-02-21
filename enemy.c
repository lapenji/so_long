/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:17:58 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 17:48:58 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_x_in_map(t_program *dt, int x, int y)
{
	if (dt->ep.x == -1 && dt->ep.y == -1)
	{
		dt->ep.x = dt->mp.x;
		dt->ep.y = dt->mp.y;
		dt->map[x][y] = '0';
	}
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->fl.ptr, dt->mp.x, dt->mp.y);
}

void	enemy_go_up(t_program *dt)
{
	if (dt->map[(dt->ep.y / TS) - 1][(dt->ep.x / TS)] != '1' && dt->win == 0)
		dt->ep.y -= TS;
}

void	enemy_go_down(t_program *dt)
{
	if (dt->map[(dt->ep.y / TS) + 1][(dt->ep.x / TS)] != '1' && dt->win == 0)
		dt->ep.y += TS;
}

void	enemy_go_left(t_program *dt)
{
	if (dt->map[(dt->ep.y / TS)][(dt->ep.x / TS) - 1] != '1' && dt->win == 0)
		dt->ep.x -= TS;
}

void	enemy_go_right(t_program *dt)
{
	if (dt->map[(dt->ep.y / TS)][(dt->ep.x / TS) + 1] != '1' && dt->win == 0)
		dt->ep.x += TS;
}
