/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:28:42 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 20:20:48 by danielji         ###   ########.fr       */
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

int		is_valid_extension(char *path, char *ext);
int		open_rdonly_file(char *path);
void	free_arr_str(char **arr);
char	**arr_string_from_fd(int fd);
int		is_texture(char *str);
int		is_color(char *str);
int		is_map(char *str);
int		is_empty_line(char *str);
void	process_file(char *path, char **arr, int *map_start);
void	init_int_arr(int *arr, int size, int value);
int		get_texture(char *line, int textures[4]);
void	process_metadata(char **arr, t_map *map, int map_start);
void	ft_trim_whitespace(char *str);
int		cardinal_to_index(char c);
int		index_to_cardinal(int i);
int		check_textures(int textures[4]);
void	close_fd_arr(int *arr, int size);
int		open_texture(int i, int textures[4], char *path);
int		validate_color(char *line);
void	get_color(char *line, t_map *map);
int		check_colors(int color[3]);

#endif
