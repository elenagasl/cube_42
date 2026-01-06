/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:28:42 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 20:34:20 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "../libft/libft.h"

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
	char		*textures[4];
	int			floor_color[3];
	int			ceiling_color[3];
}	t_game;

// Parser

void	parse_file(char *path, t_game *g);
int		open_cub_file(char *path);
int		is_valid_file(char **file);
int		is_empty_line(char *str);
int		is_first_map_line(char *str);
void	parse_textures(t_game *g, char **lines);
int		is_texture(char *str);
void	get_texture_path(char *textures[4], char *line);
int		cardinal_to_index(char c);
int		index_to_cardinal(int i);
void	parse_colors(t_game *g, char **lines);
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
int		is_char_in_set(char c, char const *set);
int		open_rdonly_file(char *path);
char	**arr_string_from_fd(int fd);
int		is_valid_extension(char *path, char *ext);
void	free_arr_str(char **arr);
void	init_int_arr(int *arr, int size, int value);
void	trim_left_ws(char *str);
void	trim_right_ws(char *str);
void	trim_whitespace(char *str);

#endif
