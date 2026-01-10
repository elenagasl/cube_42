/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:00:52 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/03 13:00:54 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include <sys/time.h>

# define WIN_W 640
# define WIN_H 480
# define MAP_W 24
# define MAP_H 7

# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;

	int			map_w;
	int			map_h;
	int			(*map)[MAP_W];

	int			floor_color;
	int			ceiling_color;

	int			color_north;
	int			color_south;
	int			color_west;
	int			color_east;

	double		time;
	double		old_time;
	double		frame_time;

	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_game;

typedef struct s_ray
{
	double	ray_dx;
	double	ray_dy;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		draw_start;
	int		draw_end;
}	t_ray;

/* map */
int		(*get_map(void))[MAP_W];

/* init */
void	init_game(t_game *g);

/* raycast */
void	init_ray(t_game *g, t_ray *r, int x);
void	init_dda(t_game *g, t_ray *r);

/* render */
void	render_frame(t_game *g);
void	cast_column(t_game *g, int x);

/* draw */
void	draw_wall(t_game *g, int x, double dist, t_ray *r);
void	put_pixel(t_img *img, int x, int y, int color);

/* move */
void	update_player(t_game *g);
void	move_forward(t_game *g, double speed);
void	move_backward(t_game *g, double speed);
void	move_left(t_game *g, double speed);
void	move_right(t_game *g, double speed);

/* utils */
int		rgb(int r, int g, int b);
double	get_time_in_seconds(void);

/* exit and hooks */
int		exit_game(t_game *g);
int		key_press(int keycode, t_game *g);
int		key_release(int keycode, t_game *g);
int		close_window(t_game *g);

#endif
