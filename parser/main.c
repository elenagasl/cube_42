/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/03 16:23:28 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"

#define ARG_INVAL	"Invalid arguments"
#define EXT_INVAL	"Invalid or missing file extension: "\
					"only .cub files are supported"

/* Return `1` if extension from `path` is the same as `valid_ext`.
Return `0` otherwise. */
int	is_valid_extension(char *path, char *valid_ext)
{
	char	*ext;
	size_t	valid_len;

	ext = ft_strrchr(path, '.');
	valid_len = ft_strlen(valid_ext);
	if (!ext || ft_strlen(ext) != valid_len)
		return (0);
	if (ft_strncmp(ext, valid_ext, valid_len) != 0)
		return (0);
	return (1);
}

/* Open a read-only file specified by `path` and return its file descriptor.
Return `-1` on error. */
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

int	main(int argc, char *argv[])
{
	int		map_fd;
	char	*path;

	if (argc != 2)
	{
		printf(ARG_INVAL"\n");
		return (1);
		// Exit ??
	}
	path = ft_strtrim(argv[1], " \t\n\v\f\r");
	if (!is_valid_extension(path, ".cub"))
	{
		printf(EXT_INVAL"\n");
		free(path);
		return (1);
		// Exit ??
	}
	else
		printf("OK!\n");
	map_fd = open_rdonly_file(path);
	(void)map_fd;
	free(path);
	return (0);
}
