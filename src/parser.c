/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 18:22:49 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	replace_char(char **arr, char c1, char c2)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == c1)
				arr[i][j] = c2;
			j++;
		}
		i++;
	}
}

/* Open .cub file, parse textures, colors and map.
Return result of validate_parsed_data (`0` or `1`) */
int	parser(t_game *g, char *path)
{
	int		fd;
	char	**arr;

	fd = open_cub_file(path);
	arr = arr_string_from_fd(fd);
	if (!arr)
		return (printf(FILE_EMPTY"\n"), 0);
	replace_char(arr, '\n', '\0');
	if (!is_valid_file(arr))
		return (free_arr_str(arr), 0);
	parse_textures(g, arr);
	parse_colors(g, arr);
	parse_map(g, arr);
	free_arr_str(arr);
	return (validate_parsed_data(g));
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
