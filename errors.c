/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:01:44 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/08 18:55:03 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	args_error(void)
{
	ft_printf("Error\nCi deve essere solo un argomento, la mappa \n");
	exit (0);
}

void	wrong_ext(void)
{
	ft_printf("Error\nEstensione file non valida \n");
	exit(0);
}

void	invalid_map(t_program *dt)
{
	ft_printf("Error\nMappa non valida");
	freemap(dt);
	exit (0);
}

void	map_too_big(t_program *dt)
{
	freemap(dt);
	ft_printf("Error\nMappa troppo grande\n");
	exit(0);
}
