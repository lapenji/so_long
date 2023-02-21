/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:47:34 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/08 17:06:19 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_create_sprite(void *mlx, char *path)
{
	t_image	image;

	image.ptr = mlx_xpm_file_to_image(mlx, path, &image.sz.x, &image.sz.y);
	image.px = mlx_get_data_addr(image.ptr, &image.bpp, &image.ls, &image.en);
	return (image);
}

void	generate_border(t_program *dt)
{
	int	i;

	i = 0;
	while (i < dt->md.x * 16)
	{
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->border.ptr, i, 0);
		i += 16;
	}
}

void	generate_moves(t_program *dt)
{
	int	i;

	i = dt->md.x - 160;
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->emme.ptr, i, 5);
	i += 10;
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->o.ptr, i, 5);
	i += 10;
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->vu.ptr, i, 5);
	i += 10;
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->e.ptr, i, 5);
	i += 10;
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->esse.ptr, i, 5);
	i += 10;
}

void	generate_moves_nbr(t_program *dt)
{
	char	*numero;
	int		x;
	int		i;

	x = dt->md.x - 90;
	i = 0;
	numero = ft_itoa(dt->moves);
	while (numero[i])
	{
		drawnumbers(dt, numero[i], x);
		i ++;
		x += 10;
	}
	free(numero);
}

void	drawnumbers(t_program *dt, char c, int x)
{
	if (c == '0')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->zero.ptr, x, 5);
	if (c == '1')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->uno.ptr, x, 5);
	if (c == '2')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->due.ptr, x, 5);
	if (c == '3')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->tre.ptr, x, 5);
	if (c == '4')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->quattro.ptr, x, 5);
	if (c == '5')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->cinque.ptr, x, 5);
	if (c == '6')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->sei.ptr, x, 5);
	if (c == '7')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->sette.ptr, x, 5);
	if (c == '8')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->otto.ptr, x, 5);
	if (c == '9')
		mlx_put_image_to_window(dt->mlx, dt->wd, dt->nove.ptr, x, 5);
}
