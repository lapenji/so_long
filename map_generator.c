/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:02:30 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/08 17:12:16 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_e_in_map(t_program *dt)
{
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->fl.ptr, dt->mp.x, dt->mp.y);
	if (dt->cc == 0)
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->pa.ptr,
			dt->mp.x, dt->mp.y);
	else
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->door_closed.ptr,
			dt->mp.x, dt->mp.y);
}

static void	get_p_in_map(t_program *dt, int x, int y)
{
	if (dt->sp.x == -1 && dt->sp.y == -1)
	{
		dt->sp.x = dt->mp.x;
		dt->sp.y = dt->mp.y;
		dt->map[x][y] = '0';
	}
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->fl.ptr, dt->mp.x, dt->mp.y);
}

static void	get_c_in_map(t_program *dt)
{
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->fl.ptr, dt->mp.x, dt->mp.y);
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->coin.ptr, dt->mp.x, dt->mp.y);
}

static void	main_map_generator(t_program *dt, int x, int y)
{
	while (dt->map[x] != NULL)
	{
		y = 0;
		while (dt->map[x][y] != '\0')
		{
			if (dt->map[x][y] == '1')
				get_wall_in_map(dt);
			else if (dt->map[x][y] == '0')
				get_floor_in_map(dt);
			else if (dt->map[x][y] == 'P')
				get_p_in_map(dt, x, y);
			else if (dt->map[x][y] == 'C')
				get_c_in_map(dt);
			else if (dt->map[x][y] == 'E')
				get_e_in_map(dt);
			else if (dt->map[x][y] == 'X')
				get_x_in_map(dt, x, y);
			dt->mp.x += TS;
			y++;
		}
		dt->mp.x = 0;
		dt->mp.y += TS;
		x++;
	}
}

void	generate_map(t_program *dt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	generate_border(dt);
	generate_moves(dt);
	generate_moves_nbr(dt);
	dt->mp.y = 16;
	dt->mp.x = 0;
	main_map_generator(dt, x, y);
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->pg.ptr, dt->sp.x, dt->sp.y);
	if (dt->ep.x != -1 && dt->ep.y != -1)
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->enemy.ptr, dt->ep.x,
			dt->ep.y);
	dt->cc = count_coins(dt->map);
	if (dt->sp.x == dt->ep.x && dt->sp.y == dt->ep.y)
	{
		dt->win = -1;
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->lost.ptr,
			(dt->md.x - dt->lost.sz.x) / 2, (dt->md.y - dt->lost.sz.y) / 2);
	}
	if (dt->win == 1)
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->vit.ptr,
			(dt->md.x - dt->vit.sz.x) / 2, (dt->md.y - dt->vit.sz.y) / 2);
}
