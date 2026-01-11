/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:05:32 by danielji          #+#    #+#             */
/*   Updated: 2026/01/11 18:23:10 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Iterate through cub file and parse paths to textures */
void	parse_textures(t_game *g, char **arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i] && count < 4)
	{
		if (is_texture(arr[i]))
		{
			get_texture_path(g->textures, arr[i]);
			count++;
		}
		i++;
	}
}

/* Save a valid path to a texture file into array of textures */
void	get_texture_path(char *textures[4], char *line)
{
	int		i;
	int		fd;
	char	type;

	trim_whitespace(line);
	if (!is_valid_extension(line, ".png"))
	{
		printf(TEXT_EXT"\n");
		return ;
	}
	type = line[0];
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (textures[cardinal_to_index(type)] != NULL)
	{
		printf(TEXT_DUP"\n");
		return ;
	}
	fd = open_rdonly_file(&line[i]);
	if (fd < 0)
		return ;
	textures[cardinal_to_index(type)] = ft_strdup(&line[i]);
	close(fd);
	return ;
}

/* Check if line is a texture line */
int	is_texture(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(&str[i], "NO", 2) == 0
		|| ft_strncmp(&str[i], "SO", 2) == 0
		|| ft_strncmp(&str[i], "WE", 2) == 0
		|| ft_strncmp(&str[i], "EA", 2) == 0)
		return (str[i + 2] && ft_isspace(str[i + 2]));
	return (0);
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
