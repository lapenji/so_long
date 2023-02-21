/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:27:35 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/08 17:14:58 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	howlong(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		i;

	i = howlong(n);
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		newstr[0] = '-';
	}
	newstr[i] = '\0';
	i--;
	while (n > 9)
	{
		newstr[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	newstr[i] = n + '0';
	return (newstr);
}

void	move_enemy(int n, t_program *program)
{
	if (n == 0)
		enemy_go_up(program);
	if (n == 1)
		enemy_go_down(program);
	if (n == 2)
		enemy_go_left(program);
	if (n == 3)
		enemy_go_right(program);
}

void	get_wall_in_map(t_program *dt)
{
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->wall.ptr, dt->mp.x, dt->mp.y);
}

void	get_floor_in_map(t_program *dt)
{
	mlx_put_image_to_window(dt->mlx, dt->wd, dt->fl.ptr, dt->mp.x, dt->mp.y);
}
