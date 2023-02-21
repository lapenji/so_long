/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:49 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 14:25:30 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_path2(t_program *data, int i, int j)
{
	if (data->mp2[i][j] == 'E')
	{
		data->ismapvalid = 0;
	}
	data->mp2[i][j] = '1';
	if (data->mp2[i][j + 1] != '1' && data->mp2[i][j + 1] != 0)
		check_valid_path2(data, i, (j + 1));
	if (data->mp2[i][j - 1] != '1' && data->mp2[i][j - 1] != 0)
		check_valid_path2(data, i, (j - 1));
	if (data->mp2[i + 1][j] != '1' && data->mp2[i + 1][j] != 0)
		check_valid_path2(data, (i + 1), j);
	if (data->mp2[i - 1][j] != '1' && data->mp2[i - 1][j] != 0)
		check_valid_path2(data, (i - 1), j);
	return (1);
}

int	check_valid_path(t_program *dt)
{
	dt->map_i = 0;
	dt->map_j = 0;
	dt->ismapvalid = 1;
	while (dt->mp2[dt->map_i][dt->map_j] != 'P')
	{
		while (dt->mp2[dt->map_i][dt->map_j])
		{
			if (dt->mp2[dt->map_i][dt->map_j] == 'P')
				return (check_valid_path2(dt, dt->map_i, dt->map_j));
			dt->map_j++;
		}
		dt->map_j = 0;
		dt->map_i++;
	}
	return (1);
}

int	is_reachable(char **map, int posx, int posy)
{
	if (map[posx][posy - 1] == '1' && map[posx][posy + 1] == '1'
		&& map[posx + 1][posy] == '1' && map[posx - 1][posy] == '1')
		return (1);
	return (0);
}

int	checkextension(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	i--;
	if (path[i] != 'r')
		return (0);
	i--;
	if (path[i] != 'e')
		return (0);
	i--;
	if (path[i] != 'b')
		return (0);
	return (1);
}

int	check_valid_chars(char **map)
{
	int	i;
	int	b;

	i = 0;
	while (map[i])
	{
		b = 0;
		while (map[i][b])
		{
			if (map[i][b] != '0' && map[i][b] != '1' && map[i][b] != 'E'
				&& map[i][b] != 'P' && map[i][b] != 'C' && map[i][b] != 'X'
				&& map[i][b] != '\n')
				return (1);
			b++;
		}
		i++;
	}
	return (0);
}
