/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:17:49 by danielji          #+#    #+#             */
/*   Updated: 2026/01/07 11:03:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Iterate through cub file until first line of map is reached.
Check for incomplete data or invalid lines */
int	is_valid_file(char **arr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (arr[i])
	{
		if (is_texture(arr[i]) || is_color(arr[i]))
			count++;
		else if (is_first_map_line(arr[i]))
		{
			if (count < 6)
				printf(MISS_DATA"\n");
			else if (count > 6)
				printf(DUP_DATA"\n");
			return (count == 6);
		}
		else if (!is_empty_line(arr[i]))
			return (printf(INV_LIN"\n"), 0);
		i++;
	}
	return (printf(MISS_MAP"\n"), 0);
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
			printf(MISS_TEXT"\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (g->floor_color[i] < 0 || g->ceiling_color[i] < 0)
			return (printf(INV_COL"\n"), 0);
		if (g->floor_color[i] > 255 || g->ceiling_color[i] > 255)
			return (printf(OOR_COL"\n"), 0);
		i++;
	}
	return (1);
}
