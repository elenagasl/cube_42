/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:05:32 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 12:32:35 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* If line starts with `N`, `S`, `W`, or `E` :
- Validate file extension
- Open texture file

TODO: WHAT ARE THE ALLOWED EXTENSIONS?????? */
int	parse_texture(char *line, int textures[4])
{
	int		i;
	char	*path;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	path = &line[i];
	if (!is_valid_extension(path, ".png"))
	{
		printf("Invalid or missing file extension: "
			"only .png [o lo que sea!] files are supported\n");
		return (0);
	}
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
	{
		if (!open_texture(cardinal_to_index(line[0]), textures, path))
			return (close_fd_arr(textures, 4), 0);
	}
	return (1);
}

/* Open a texture file indicated by `path` and
assign it to corresponding texture array index */
int	open_texture(int i, int textures[4], char *path)
{
	int	fd;

	if (textures[i] != -1)
	{
		printf("Error: Duplicated '%c' texture\n", index_to_cardinal(i));
		return (0);
	}
	fd = open_rdonly_file(path);
	textures[i] = fd;
	if (fd < 0)
		return (0);
	return (1);
}

/* Check if all 4 file descriptor textures have been assigned */
int	check_textures(int textures[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (textures[i] == -1)
		{
			close_fd_arr(textures, 4);
			return (0);
		}
		i++;
	}
	return (1);
}

// TODO Mejor usar enum?
int	cardinal_to_index(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (2);
	else if (c == 'E')
		return (3);
	return (-1);
}

// TODO Mejor usar enum?
int	index_to_cardinal(int i)
{
	if (i == 0)
		return ('N');
	else if (i == 1)
		return ('S');
	else if (i == 2)
		return ('W');
	else if (i == 3)
		return ('E');
	return ('0');
}
