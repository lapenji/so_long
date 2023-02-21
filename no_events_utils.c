/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_events_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:26:55 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 11:58:47 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	randandmove(t_program *data)
{
	int	i;

	i = myrandinrange(0, 3);
	mlx_clear_window(data->mlx, data->wd);
	if (data->ep.x != -1 && data->ep.y != -1)
		move_enemy(i, data);
	data->sp.y -= 1;
	generate_map(data);
}

void	animatepg(t_program *data)
{
	mlx_clear_window(data->mlx, data->wd);
	data->sp.y += 1;
	generate_map(data);
}
