/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:00:52 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/11 20:23:06 by danielji         ###   ########.fr       */
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
# include <X11/keysym.h>

# define ARG_INVAL "Invalid argument. Usage: .cub3d <filename>.cub"
# define FILE_EMPTY "Error: Empty file"
# define FILE_EXT "Error: Only .cub files are supported"
# define DATA_MISS "Error: Missing data"
# define DATA_DUP "Error: Duplicated data"
# define TEXT_EXT "Error: Only .png texture files are supported"
# define TEXT_DUP "Error: Duplicated texture"
# define TEXT_MISS "Error: Missing texture file"
# define COLOR_INVAL "Error: Missing or invalid color"
# define COLOR_RANGE "Error: Out of range color"
# define MAP_MISS "Error: Missing map"
# define MAP_TOP_INVAL "Error: Invalid map top line"
# define MAP_BOT_INVAL "Error: Invalid map bottom line"
# define MAP_LINE_INVAL "Error: Invalid map line"
# define MAP_OPEN "Error: Space not surrounded by wall"
# define MAP_SIZE_INVAL "Error: Invalid map size"
# define LINE_INVAL "Error: Invalid line"
# define LINE_UNEXP "Error: Unexpected line"
# define PLYR_MISS "Error: Missing player position"
# define PLYR_MULTI "Error: No more than one player position allowed"

# define WIN_W 640
# define WIN_H 480
//# define MAP_W 24
//# define MAP_H 7

// MacOS
//# define KEY_ESC	53
//# define KEY_LEFT	123
//# define KEY_RIGHT	124
//# define KEY_W		13
//# define KEY_A		0
//# define KEY_S		1
//# define KEY_D		2

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
	//int			(*map)[MAP_W];

	int			floor_color;
	int			ceiling_color;

	char		*textures[4];
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
//int		(*get_map(void))[MAP_W];

/* init */
void	init_game(t_game *g);
void	init_parser(t_game *g);

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
int		rgb_arr(int color[3]);
double	get_time_in_seconds(void);

/* exit and hooks */
void	free_parser(t_game *g);
int		exit_game(t_game *g);
int		key_press(int keycode, t_game *g);
int		key_release(int keycode, t_game *g);
int		close_window(t_game *g);

/* Parser */

void	parser(t_game *g, int argc, char *path);
void	parse_textures(t_game *g, char **arr);
void	parse_colors(t_game *g, char **arr);
int		parse_rgb(char *line);
int		parse_map(t_game *g, char **arr);

int		open_cub_file(char *path);
int		is_valid_file(char **arr);
int		is_empty_line(char *str);
int		is_first_map_line(char *str);
int		is_texture(char *str);
void	get_texture_path(char *textures[4], char *line);
int		cardinal_to_index(char c);
int		index_to_cardinal(int i);
int		is_color(char *str);
int		is_valid_color(char *str);
void	print_parsed_data(t_game *g);
int		validate_parsed_data(t_game *g);
int		is_valid_map(char **arr, char player, int h);
int		is_valid_top_bottom_line(char *str);
char	get_player(t_game *g, char **arr);
void	set_player(t_game *g, int y, int x, char p);
int		is_valid_map_line(char *str, char p);
void	get_map_size(t_game *g, char **arr);
void	normalize_map_spaces(char **arr, int h, int w);
int		map_to_int_arr(t_game *g, char **arr, char p);
int		**allocate_map(int w, int h);
int		is_char_in_set(char c, char const *set);
int		is_surrounded(char **arr, int r, int c);
int		flood_fill(char **arr, char p, int h);
int		open_rdonly_file(char *path);
char	**arr_string_from_fd(int fd);
int		is_valid_extension(char *path, char *ext);
void	free_arr_str(char **arr);
void	free_arr_int(int **arr, int size);
void	free_textures(char **arr);
void	init_int_arr(int *arr, int size, int value);
void	trim_left_ws(char *str);
void	trim_right_ws(char *str);
void	trim_whitespace(char *str);
void	print_mini_map(t_game *g);
void	print_parsed_data(t_game *g);
void	replace_char(char **arr, char c1, char c2);

#endif
