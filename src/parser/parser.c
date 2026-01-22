/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/22 18:38:09 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Open a read-only file specified by `path` and return its file descriptor.
On error print message and return `-1`.*/
int	open_rdonly_file(char *path)
{
	int	fd;
	int	err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		err = errno;
		printf("Error\n%s: %s\n", strerror(err), path);
		return (-1);
	}
	return (fd);
}

/* Open .cub file indicated by `path` and return file descriptor.
On error exit program */
static int	open_cub_file(char *path)
{
	int	fd;

	trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf(FILE_EXT"\n");
		exit(1);
	}
	fd = open_rdonly_file(path);
	if (fd < 0)
		exit(1);
	return (fd);
}

/* Read file `fd` line by line an return an array
of the read strings or `NULL` in case of error*/
static char	**arr_string_from_fd(int fd)
{
	char	**arr;
	char	*line;

	arr = NULL;
	line = get_next_line(fd);
	while (line)
	{
		arr = ft_push_str_to_arr(arr, line);
		if (!arr)
			return (free(line), NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

/* Open .cub file, parse textures, colors and map.
On error free allocated memory and exit program */
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
	{
		free_parser(g);
		exit(1);
	}
}
