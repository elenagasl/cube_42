/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:00:52 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/22 18:17:09 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/time.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "errors.h"
# include <X11/keysym.h>

# define WIN_W 1280
# define WIN_H 960
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define MARGIN 0.1

# define KEY_ESC	XK_Escape
# define KEY_LEFT	XK_Left
# define KEY_RIGHT	XK_Right
# define KEY_W		XK_w
# define KEY_A		XK_a
# define KEY_S		XK_s
# define KEY_D		XK_d

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
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
	int			**map;
	int			floor_color;
	int			ceiling_color;
	char		*text_paths[4];
	t_img		textures[4];
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
	double	dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
}	t_ray;

/* Init */

void	init_game(t_game *g);
void	init_parser(t_game *g);

/* Raycast */

void	init_ray(t_game *g, t_ray *r, int x);
void	init_dda(t_game *g, t_ray *r);
int		perform_dda(t_game *g, t_ray *r);
double	get_perp_dist(t_game *g, t_ray *r);
void	cast_column(t_game *g, int x);

/* Render */

void	render_frame(t_game *g);
void	put_pixel(t_img *img, int x, int y, int color);

/* Draw */

void	draw_ceiling_floor(t_game *g, int x, int start, int end);
void	draw_wall(t_game *g, int x, t_ray *r);
void	draw_texture_column(t_game *g, t_img *t, int x, t_ray *r);

/* Move */

int		is_walkable(t_game *g, int x, int y);
void	rotate(t_player *p, double rot_speed);
void	move_longitudinal(t_game *g, double speed, int dir);
void	move_lateral(t_game *g, double speed, int dir);
void	update_player(t_game *g);

/* Utils */

int		rgb(int r, int g, int b);
double	get_time_in_seconds(void);

/* Exit and hooks */

void	free_textures(char **arr);
void	free_arr_int(int **arr, int size);
void	free_parser(t_game *g);
void	destroy_images(t_game *g);
void	exit_game(t_game *g, int status);

/* Hooks */

int		key_release(int keycode, t_game *g);
int		key_press(int keycode, t_game *g);
int		close_window(t_game *g);

/* Parser */

void	parser(t_game *g, int argc, char *path);
int		open_rdonly_file(char *path);
int		validate_parsed_data(t_game *g);
int		is_first_map_line(char *str);
int		is_empty_line(char *str);
int		is_valid_file(char **arr);

/* Parse textures & colors */

void	parse_textures(t_game *g, char **arr);
void	parse_colors(t_game *g, char **arr);
int		is_texture(char *str);
int		is_color(char *str);

/* Parse map */

int		parse_map(t_game *g, char **arr);
void	get_map_size(t_game *g, char **arr);
void	normalize_map_spaces(char **arr, int h, int w);
int		is_valid_map(char **arr, char player, int h);
int		flood_fill(char **arr, char p, int h);
int		is_surrounded(char **arr, int y, int x);
char	get_player(t_game *g, char **arr);
int		map_to_int_arr(t_game *g, char **arr, char p);

/* Parser utils */

void	print_parsed_data(t_game *g);
int		is_valid_extension(char *path, char *ext);
void	free_arr_str(char **arr);
void	init_int_arr(int *arr, int size, int value);
int		is_char_in_set(char c, char const *set);
void	replace_char(char **arr, char c1, char c2);
void	trim_left_ws(char *str);
void	trim_right_ws(char *str);
void	trim_whitespace(char *str);

#endif
