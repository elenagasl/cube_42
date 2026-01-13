/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:06:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/13 22:48:13 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Iterate through cub file and parse floor and ceiling colors */
void	parse_colors(t_game *g, char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (is_color(arr[i]))
		{
			trim_whitespace(arr[i]);
			if (arr[i][0] == 'F')
				g->floor_color = parse_rgb(&arr[i][1]);
			else if (arr[i][0] == 'C')
				g->ceiling_color = parse_rgb(&arr[i][1]);
		}
		i++;
	}
}

/* Previous version:
	while (ft_isdigit(line[i]))
	{
		value *= 10;
		value += line[i] - '0';
		i++;
	}
 */
/* Parse an RGB color-coded string into an array of integers */
int	parse_rgb(char *line)
{
	int	i;
	int	value;
	int	color_index;
	int	color[3];

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!is_valid_color(&line[i]))
		return (printf(COLOR_INVAL"\n"), -1);
	color_index = 0;
	init_int_arr(color, 3, -1);
	while (line[i] && color_index < 3)
	{
		value = 0;
		while (ft_isdigit(line[i]))
			value = (10 * value) + line[i++] - '0';
		if (value > 255)
			return (printf(COLOR_RANGE"\n"), -1);
		else
			color[color_index] = value;
		color_index++;
		i++;
	}
	return (rgb(color[0], color[1], color[2]));
}

/* Check if `str` is a valid color format:
- There are only 3 numbers less than four digits long
- Each number is separated by a single comma 
- No other characters are allowed */
int	is_valid_color(char *str)
{
	int	i;
	int	comma;
	int	digit;

	i = 0;
	comma = 0;
	digit = 0;
	while (str[i])
	{
		if (comma > 2 || digit > 3)
			return (0);
		if (ft_isdigit(str[i]))
			digit++;
		else if (str[i] == ',')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
			digit = 0;
			comma++;
		}
		else
			return (0);
		i++;
	}
	return (comma == 2);
}

/* Check if line is a floor or ceiling color line */
int	is_color(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 'F' || str[i] == 'C')
	{
		if (str[i + 1] && ft_isspace(str[i + 1]))
			return (1);
	}
	return (0);
}
