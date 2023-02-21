/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:32:21 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 13:18:29 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_program *data)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		free(data->mp2[x]);
		free(data->map[x]);
		x++;
	}
	free (data->map);
	free (data->mp2);
}

static void	destroy_sprites(t_program *data)
{
	mlx_destroy_image(data->mlx, data->wall.ptr);
	mlx_destroy_image(data->mlx, data->fl.ptr);
	mlx_destroy_image(data->mlx, data->pg.ptr);
	mlx_destroy_image(data->mlx, data->coin.ptr);
	mlx_destroy_image(data->mlx, data->pa.ptr);
	mlx_destroy_image(data->mlx, data->door_closed.ptr);
	mlx_destroy_image(data->mlx, data->border.ptr);
	mlx_destroy_image(data->mlx, data->enemy.ptr);
	mlx_destroy_image(data->mlx, data->vit.ptr);
	mlx_destroy_image(data->mlx, data->lost.ptr);
}

static void	destroy_font(t_program *data)
{
	mlx_destroy_image(data->mlx, data->emme.ptr);
	mlx_destroy_image(data->mlx, data->o.ptr);
	mlx_destroy_image(data->mlx, data->vu.ptr);
	mlx_destroy_image(data->mlx, data->e.ptr);
	mlx_destroy_image(data->mlx, data->esse.ptr);
	mlx_destroy_image(data->mlx, data->zero.ptr);
	mlx_destroy_image(data->mlx, data->uno.ptr);
	mlx_destroy_image(data->mlx, data->due.ptr);
	mlx_destroy_image(data->mlx, data->tre.ptr);
	mlx_destroy_image(data->mlx, data->quattro.ptr);
	mlx_destroy_image(data->mlx, data->cinque.ptr);
	mlx_destroy_image(data->mlx, data->sei.ptr);
	mlx_destroy_image(data->mlx, data->sette.ptr);
	mlx_destroy_image(data->mlx, data->otto.ptr);
	mlx_destroy_image(data->mlx, data->nove.ptr);
}

void	fre_all(t_program *program)
{
	destroy_font(program);
	destroy_sprites(program);
	mlx_destroy_window(program->mlx, program->wd);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	freemap(program);
}
