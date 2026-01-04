/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:06:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 21:20:10 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

/* - Parse an RGB color-coded string into an array of integer
- Save color value into corresponding array position */
void	parse_color(char *line, int color[3])
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

int	restart_comma(char next_char, int *commas, int *digits)
{
	if (!ft_isdigit(next_char) && next_char != '\0')
		return (0);
	if (*digits == 0 || *digits > 3)
		return (0);
	*commas += 1;
	*digits = 0;
	return (1);
}

/* Check if a line is a valid color line:
- 'F' or 'C' may be followed by whitespace
- There are only 3 numbers
- Numbers are less than four digits long
- Each number is separated by a single comma */
int	validate_color(char *line)
{
	int	i;
	int	commas;
	int	digits;

	i = 0;
	commas = 0;
	digits = 0;
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] == ',' && !restart_comma(line[i + 1], &commas, &digits))
			return (printf("Error: invalid color format\n"), 0);
		else if (ft_isdigit(line[i]))
			digits++;
		else if (!ft_isdigit(line[i]) && line[i] != ',')
			return (printf("Error: invalid color format BBBBBBBB\n"), 0);
		i++;
	}
	if (commas != 2 || digits == 0 || digits > 3)
		return (printf("Error: invalid color format\n"), 0);
	return (1);
}

/* - Check if line has a valid color format
- Parse floor or ceiling color into an array of integers
TODO: Do something if `validate_color` fails !!!*/
void	get_color(char *line, t_map *map)
{
	int	i;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	if (validate_color(line))
	{
		if (line[0] == 'F')
			parse_color(&line[1], map->floor_color);
		else if (line[0] == 'C')
			parse_color(&line[1], map->ceiling_color);
	}
}
