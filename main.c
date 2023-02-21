/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:11:46 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 12:24:22 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroywin(t_program *dt)
{
	fre_all(dt);
	exit(0);
}

int	handlenoevents(t_program *dt)
{
	static int	frame;

	frame++;
	if (frame == 30000 && dt->win == 0)
		animatepg(dt);
	if (frame == 60000 && dt->win == 0)
	{
		randandmove(dt);
		frame = 0;
	}
	if (dt->ep.x == dt->sp.x && dt->ep.x == dt->sp.y)
		dt->win = -1;
	return (0);
}

int	handlekeys(int ks, t_program *dt)
{
	mlx_clear_window(dt->mlx, dt->wd);
	if (ks == 65307)
	{
		fre_all(dt);
		exit(0);
	}
	if (ks == 100 && dt->map[(dt->sp.y / TS)][(dt->sp.x / TS) + 1]
		!= '1' && dt->win == 0)
		go_right(dt);
	if (ks == 97 && dt->map[(dt->sp.y / TS)][(dt->sp.x / TS) - 1]
		!= '1' && dt->win == 0)
		go_left(dt);
	if (ks == 119 && dt->map[(dt->sp.y / TS) - 1][(dt->sp.x / TS)]
		!= '1' && dt->win == 0)
		go_up(dt);
	if (ks == 115 && dt->map[(dt->sp.y / TS) + 1][(dt->sp.x / TS)]
		!= '1' && dt->win == 0)
		go_down(dt);
	generate_map(dt);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	dt;

	if (argc != 2)
		args_error();
	if (checkextension(argv[1]) == 0)
		wrong_ext();
	mapreader(argv[1], &dt);
	if (check_map(&dt) == 1)
		invalid_map(&dt);
	dt.md.y = (count_height(dt.map) * TS) + 16;
	dt.md.x = count_base(dt.map) * TS;
	if (dt.md.x > 1920 || dt.md.y > 1080)
		map_too_big(&dt);
	dt.cc = count_coins(dt.map);
	dt.mlx = mlx_init();
	populate_images(&dt);
	populate_font(&dt);
	dt.wd = mlx_new_window(dt.mlx, dt.md.x, dt.md.y + TS, "lapenji");
	generate_map(&dt);
	mlx_loop_hook(dt.mlx, handlenoevents, &dt);
	mlx_key_hook(dt.wd, handlekeys, &dt);
	mlx_hook(dt.wd, 17, 0, destroywin, &dt);
	mlx_loop(dt.mlx);
	mlx_destroy_display(dt.mlx);
	free(dt.mlx);
}
