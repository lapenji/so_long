/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:12:59 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 17:38:59 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int	count_lines(char *file)
{
	int		i;
	int		fd;
	int		readcount;
	char	c;

	readcount = 1;
	i = 0;
	fd = open(file, O_RDONLY);
	while (readcount > 0)
	{
		readcount = read(fd, &c, 1);
		if (c == '\n')
			i++;
	}
	close(fd);
	return (i - 1);
}

void	mapreader(char *file, t_program *program)
{
	int		b;
	int		count;
	int		fd;

	b = 0;
	count = count_lines(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("file non esistente, esco \n");
		exit(0);
	}
	program->map = (char **) malloc (sizeof(char *) * (count + 1));
	program->mp2 = (char **) malloc (sizeof (char *) * (count + 1));
	while (b < count)
	{
		program->map[b] = get_next_line(fd);
		program->mp2[b] = strdup(program->map[b]);
		b++;
	}
	program->map[b] = NULL;
	program->mp2[b] = NULL;
	close(fd);
}
