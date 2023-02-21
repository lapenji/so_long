/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:06:41 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 14:30:21 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	populate_images(t_program *program)
{
	program->wall = ft_create_sprite(program->mlx, "./sprites/wall.xpm");
	program->fl = ft_create_sprite(program->mlx, "./sprites/floor.xpm");
	program->pg = ft_create_sprite(program->mlx, "./sprites/personaggio.xpm");
	program->coin = ft_create_sprite(program->mlx, "./sprites/coin.xpm");
	program->pa = ft_create_sprite(program->mlx, "./sprites/open.xpm");
	program->door_closed = ft_create_sprite(program->mlx, "./sprites/clos.xpm");
	program->border = ft_create_sprite(program->mlx, "./sprites/border.xpm");
	program->enemy = ft_create_sprite(program->mlx, "./sprites/enemy.xpm");
	program->vit = ft_create_sprite(program->mlx, "./sprites/vittoria.xpm");
	program->lost = ft_create_sprite(program->mlx, "./sprites/lost.xpm");
	program->sp.x = -1;
	program->sp.y = -1;
	program->win = 0;
	program->moves = 0;
	program->ep.x = -1;
	program->ep.y = -1;
}

void	populate_font(t_program *program)
{
	program->emme = ft_create_sprite(program->mlx, "./font/emme.xpm");
	program->o = ft_create_sprite(program->mlx, "./font/o.xpm");
	program->vu = ft_create_sprite(program->mlx, "./font/vu.xpm");
	program->e = ft_create_sprite(program->mlx, "./font/e.xpm");
	program->esse = ft_create_sprite(program->mlx, "./font/esse.xpm");
	program->zero = ft_create_sprite(program->mlx, "./font/zero.xpm");
	program->uno = ft_create_sprite(program->mlx, "./font/uno.xpm");
	program->due = ft_create_sprite(program->mlx, "./font/due.xpm");
	program->tre = ft_create_sprite(program->mlx, "./font/tre.xpm");
	program->quattro = ft_create_sprite(program->mlx, "./font/qua.xpm");
	program->cinque = ft_create_sprite(program->mlx, "./font/cinq.xpm");
	program->sei = ft_create_sprite(program->mlx, "./font/sei.xpm");
	program->sette = ft_create_sprite(program->mlx, "./font/sette.xpm");
	program->otto = ft_create_sprite(program->mlx, "./font/otto.xpm");
	program->nove = ft_create_sprite(program->mlx, "./font/nove.xpm");
}

static int	myrand(void)
{
	static int	next = 3251;

	next = ((next * next) / 100) % 10000 ;
	return (next);
}

int	myrandinrange(int min, int max)
{
	return (myrand() % (max + 1 - min) + min);
}
