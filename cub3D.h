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

# define WIN_W 640
# define WIN_H 480
# define MAP_W 24
# define MAP_H 7

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
void	draw_wall(t_game *g, int x, double dist, int side);
void	draw_vertical_line(t_game *g, int x, int start, int end);
void	put_pixel(t_img *img, int x, int y, int color);

/* utils */
int		rgb(int r, int g, int b);

#endif
