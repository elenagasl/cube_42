/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:28:42 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 09:39:14 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_map
{
	int	textures[4];
	int	floor_color[3];
	int	ceiling_color[3];
}		t_map;

// Argument validation

int		validate_arg(int argc, char *path);
int		is_valid_extension(char *path, char *ext);


// Open and read .cub file

int		open_rdonly_file(char *path);
char	**arr_string_from_fd(int fd);


// File validation

int		validate_file(char *path, char **arr, int *map_start);
int		is_texture(char *str);
int		is_color(char *str);
int		is_map(char *str);
int		is_empty_line(char *str);
void	count_lines(char *line, int *i, int *count, int *map_start);
int		file_validation_status(int count, int map_start);


// Metadata parsing

int		parse_metadata(char **arr, t_map *map, int map_start);


// Metadata parsing: textures

int		parse_texture(char *line, int textures[4]);
int		open_texture(int i, int textures[4], char *path);
int		check_textures(int textures[4]);
int		cardinal_to_index(char c);
int		index_to_cardinal(int i);


// Metadata parsing: colors

void	parse_color(char *line, t_map *map);
void	parse_rgb(char *line, int color[3]);
int		check_colors(int color[3]);
int		restart_comma(char next_char, int *commas, int *digits);
int		validate_color(char *line);


// Map parsing

int		parse_map(char **arr, t_map *map);


// Trim whitespace

void	ft_trim_ws_left(char *str);
void	ft_trim_ws_right(char *str);
void	ft_trim_whitespace(char *str);


// Utils

void	free_arr_str(char **arr);
void	init_int_arr(int *arr, int size, int value);
void	close_fd_arr(int *arr, int size);

#endif
