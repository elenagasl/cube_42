/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/11 19:26:41 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Open .cub file, parse textures, colors and map.
Return result of validate_parsed_data (`0` or `1`) */
void	parser(t_game *g, int argc, char *path)
{
	int		fd;
	char	**arr;

	if (argc != 2)
		return (printf(ARG_INVAL"\n"), exit(1));
	init_parser(g);
	fd = open_cub_file(path);
	arr = arr_string_from_fd(fd);
	if (!arr)
		return (printf(FILE_EMPTY"\n"), free_parser(g), exit(1));
	replace_char(arr, '\n', '\0');
	if (!is_valid_file(arr))
		return (free_arr_str(arr), free_parser(g), exit(1));
	parse_textures(g, arr);
	parse_colors(g, arr);
	parse_map(g, arr);
	free_arr_str(arr);
	if (!validate_parsed_data(g))
		return (free_parser(g), exit(1));
}

/* Open .cub file indicated in `path` and return file descriptor */
int	open_cub_file(char *path)
{
	int	fd;

	trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf(FILE_EXT"\n");
		return (-1);
	}
	fd = open_rdonly_file(path);
	return (fd);
}

void	free_textures(char **arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}
