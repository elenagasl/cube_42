/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:28:42 by danielji          #+#    #+#             */
/*   Updated: 2026/01/08 17:40:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"

# define WIN_W 640
# define WIN_H 480
# define MAP_W 24
# define MAP_H 7

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
# define MAP_SIZE_INVAL "Error: Invalid map size"
# define LINE_INVAL "Error: Invalid line"
# define LINE_UNEXP "Error: Unexpected line"
# define PLYR_MISS "Error: Missing player position"
# define PLYR_MULTI "Error: No more than one player position allowed"

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
	char		*textures[4];
	int			floor_arr[3];
	int			floor;
	int			ceiling_arr[3];
	int			ceiling;
}	t_game;

// Parser

int		parser(t_game *g, char *path);
int		open_cub_file(char *path);
void	free_cub3d(t_game *g);
int		is_valid_file(char **arr);
int		is_empty_line(char *str);
int		is_first_map_line(char *str);
void	parse_textures(t_game *g, char **arr);
int		is_texture(char *str);
void	get_texture_path(char *textures[4], char *line);
int		cardinal_to_index(char c);
int		index_to_cardinal(int i);
void	parse_colors(t_game *g, char **arr);
int		is_color(char *str);
int		is_valid_color(char *str);
void	parse_rgb(char *line, int color[3]);
void	print_parsed_data(t_game *g);
int		validate_parsed_data(t_game *g);
void	parse_map(t_game *g, char **arr);
int		is_valid_map(char **arr, char player);
int		is_valid_top_bottom_line(char *str);
char	get_player(char **arr);
int		is_valid_map_line(char *str, char p);
void	get_map_size(t_game *g, char **arr);
int		map_to_int_arr(t_game *g, char **arr, char p);
int		**allocate_map(int w, int h);
int		is_char_in_set(char c, char const *set);
int		is_surrounded(char **arr, int x, int y);
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

int		rgb(int color[3]);

#endif
