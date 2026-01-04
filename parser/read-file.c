/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read-file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:09:29 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 23:42:05 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Open a read-only file specified by `path` and return its file descriptor.
On error print message and return `-1`.
TODO: On error should exit program ????*/
int	open_rdonly_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	return (fd);
}

/* Read file `fd` line by line an return an array
of the read strings or `NULL` in case of error
TODO: Free GNL static ???*/
char	**arr_string_from_fd(int fd)
{
	char	**arr;
	char	*line;

	arr = NULL;
	line = get_next_line(fd);
	while (line)
	{
		arr = ft_push_str_to_arr(arr, line);
		if (!arr)
		{
			free(line);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (arr);
}
