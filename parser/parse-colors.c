/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:06:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 00:00:40 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* - Check if line has a valid color format
- Parse floor or ceiling color into an array of integers*/
void	parse_color(char *line, t_map *map)
{
	int	i;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	if (line[0] == 'F')
		parse_rgb(&line[1], map->floor_color);
	else if (line[0] == 'C')
		parse_rgb(&line[1], map->ceiling_color);
}

/* - Parse an RGB color-coded string into an array of integer
- Save color value into corresponding array position */
void	parse_rgb(char *line, int color[3])
{
	int	i;
	int	value;
	int	color_index;

	i = 0;
	value = 0;
	color_index = 0;
	while (ft_isspace(line[i]))
		i++;
	while (color_index < 3)
	{
		if (line[i] == ',' || line[i] == '\0')
		{
			color[color_index] = value;
			value = 0;
			color_index++;
			i++;
			continue ;
		}
		value *= 10;
		value += line[i] - '0';
		i++;
	}
}

/* Check if all colors have been assigned properly
No color can hold a value greater than 255 */
int	check_colors(int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			return (0);
		if (color[i] > 255)
		{
			printf("Error: Out of range color\n");
			return (0);
		}
		i++;
	}
	return (1);
}
