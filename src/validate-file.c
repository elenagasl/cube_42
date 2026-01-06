/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:17:49 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 21:22:04 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Iterate through cub file until first line of map is reached.
Check for incomplete data or invalid lines */
int	is_valid_file(char **lines)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (lines[i])
	{
		if (is_texture(lines[i]) || is_color(lines[i]))
			count++;
		else if (is_first_map_line(lines[i]))
		{
			if (count < 6)
				printf("Error: Missing data\n");
			else if (count > 6)
				printf("Error: Duplicated data\n");
			return (count == 6);
		}
		else if (!is_empty_line(lines[i]))
			return (printf("Error: Invalid line\n"), 0);
		i++;
	}
	return (printf("Error: Missing map\n"), 0);
}

/* Check if a line is composed of whitespace only */
int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

/* Check if line is the starting line of the map */
int	is_first_map_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}

/* Check if textures and colors are valid and have been parsed properly */
int	validate_parsed_data(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!g->textures[i])
		{
			printf("Error: Missing %c texture file\n", index_to_cardinal(i));
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (g->floor_color[i] < 0 || g->ceiling_color[i] < 0)
			return (printf("Error: Missing or invalid color\n"), 0);
		if (g->floor_color[i] > 255 || g->ceiling_color[i] > 255)
			return (printf("Error: Out of range color\n"), 0);
		i++;
	}
	return (1);
}
