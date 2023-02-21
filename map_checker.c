/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:19:10 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 17:43:06 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkchar(char **map, int rows, char c)
{
	int	i;
	int	x;
	int	counter;

	i = 0;
	x = 1;
	counter = 0;
	while (x < rows)
	{
		i = 0;
		while (map[x][i])
		{
			if (map[x][i] == c)
				counter++;
			i++;
		}
		x++;
	}
	return (counter);
}

int	checkupndownwalls(char **map, int rows)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[rows][i] != '\n')
	{
		if (map[rows][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	checkleftnrightwalls(char **map, int rows, int columns)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][columns -1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	firstmapcheck(t_program *dt)
{
	int	rows;
	int	columns;

	rows = count_height(dt->mp2);
	columns = count_base(dt->mp2);
	if (checkchar(dt->mp2, rows, 'C') < 1)
		return (1);
	if (checkchar(dt->mp2, rows, 'P') != 1)
		return (1);
	if (checkchar(dt->mp2, rows, 'E') != 1)
		return (1);
	if (checkchar(dt->mp2, rows, 'X') > 1)
		return (1);
	if (checkleftnrightwalls(dt->mp2, rows, columns) == 1)
		return (1);
	if (check_valid_chars(dt->mp2) == 1)
		return (1);
	if (check_map_square(dt) == 1)
		return (1);
	if (checkupndownwalls(dt->map, rows) == 1)
		return (1);
	return (0);
}

int	check_map(t_program *dt)
{
	int	i;
	int	y;

	y = 1;
	if (firstmapcheck(dt) == 1)
		return (1);
	while (dt->mp2[y] != 0)
	{
		i = 0;
		while (dt->mp2[y][i])
		{
			if (dt->mp2[y][i] == 'C' || dt->mp2[y][i] == 'P'
				|| dt->mp2[y][i] == 'E')
			{
				if (is_reachable(dt->mp2, y, i) == 1)
					return (1);
			}
			i++;
		}
		y++;
	}
	check_valid_path(dt);
	if (dt->ismapvalid == 1)
		return (1);
	return (0);
}
