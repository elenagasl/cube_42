/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:09:29 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 14:31:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if `path` ends with indicated extension `ext`.
Extension must begin with dot: `.cub`, `.png`, etc. */
int	is_valid_extension(char *path, char *ext)
{
	char	*path_ext;
	size_t	len;

	path_ext = ft_strrchr(path, '.');
	len = ft_strlen(ext);
	if (!path_ext)
		return (0);
	if (ft_strlen(path_ext) != len)
		return (0);
	if (ft_strncmp(path_ext, ext, len) != 0)
		return (0);
	return (1);
}

/* Open a read-only file specified by `path` and return its file descriptor.
On error print message and return `-1`.*/
int	open_rdonly_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (-1);
		// Exit??
	}
	return (fd);
}

/* Read file `fd` line by line an return an array of the read strings
or `NULL` in case of error */
char	**arr_string_from_fd(int fd)
{
	char	**arr;
	char	*line;

	arr = NULL;
	line = get_next_line(fd);
	while (line)
	{
		arr = ft_push_str_to_arr(arr, line);
		line = get_next_line(fd);
	}
	// TODO: Free GNL static
	return (arr);
}
