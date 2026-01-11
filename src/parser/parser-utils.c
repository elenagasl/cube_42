/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:28:18 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 17:58:54 by danielji         ###   ########.fr       */
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
		printf("Error: %s: %s\n", strerror(err), path);
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
			return (free(line), NULL);
		line = get_next_line(fd);
	}
	close(fd);
	return (arr);
}

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

/* Free an array of strings */
void	free_arr_str(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
	arr = NULL;
}

/* Initialize each integer in an array to passed `value` */
void	init_int_arr(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = value;
		i++;
	}
}

int	is_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

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
