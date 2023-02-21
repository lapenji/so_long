/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltombell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:51:29 by ltombell          #+#    #+#             */
/*   Updated: 2022/11/09 17:46:25 by ltombell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

# define TS 48

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_image
{
	void		*ptr;
	t_vector	sz;
	char		*px;
	int			bpp;
	int			ls;
	int			en;
	t_vector	position;
}	t_image;

typedef struct s_program
{
	int			ismapvalid;
	int			map_j;
	int			map_i;
	t_vector	ep;
	t_vector	mp;
	void		*mlx;
	void		*wd;
	t_vector	sp;
	char		**mp2;
	char		**map;
	t_vector	md;
	int			cc;
	int			moves;
	t_image		wall;
	t_image		pa;
	t_image		door_closed;
	t_image		pg;
	t_image		fl;
	t_image		coin;
	t_image		border;
	t_image		emme;
	t_image		o;
	t_image		vu;
	t_image		e;
	t_image		esse;
	t_image		zero;
	t_image		uno;
	t_image		due;
	t_image		tre;
	t_image		quattro;
	t_image		cinque;
	t_image		sei;
	t_image		sette;
	t_image		otto;
	t_image		nove;
	t_image		vit;
	t_image		lost;
	int			win;
	t_image		enemy;
}				t_program;

void	populate_font(t_program *program);
void	populate_images(t_program *program);
t_image	ft_create_sprite(void *mlx, char *path);
void	mapreader(char *file, t_program *program);
int		count_lines(char *file);
char	*ft_itoa(int n);
t_image	ft_create_sprite(void *mlx, char *path);
void	generate_border(t_program *program);
void	generate_moves(t_program *program);
void	drawnumbers(t_program *program, char c, int x);
void	generate_moves_nbr(t_program *program);
void	generate_moves(t_program *program);
void	generate_border(t_program *program);
t_image	ft_create_sprite(void *mlx, char *path);
int		count_coins(char **mappa);
int		count_base(char **mappa);
int		count_height(char **mappa);
void	go_up(t_program *data);
void	go_down(t_program *data);
void	go_left(t_program *data);
void	go_right(t_program *data);
void	generate_map(t_program *program);
void	get_x_in_map(t_program *data, int x, int y);
void	enemy_go_up(t_program *data);
void	enemy_go_down(t_program *data);
void	enemy_go_left(t_program *data);
void	enemy_go_right(t_program *data);
int		generate_rand(int n, t_program *program);
void	move_enemy(int n, t_program *program);
int		check_map(t_program *program);
void	freemap(t_program *data);
void	fre_all(t_program *program);
int		checkextension(char *path);
void	animatepg(t_program *data);
void	randandmove(t_program *data);
void	args_error(void);
void	wrong_ext(void);
void	invalid_map(t_program *dt);
void	map_too_big(t_program *dt);
int		check_valid_path(t_program *dt);
int		is_reachable(char **map, int posx, int posy);
void	get_wall_in_map(t_program *dt);
void	get_floor_in_map(t_program *dt);
int		check_valid_chars(char **map);
int		myrandinrange(int min, int max);
int		check_map_square(t_program *dt);

#endif
