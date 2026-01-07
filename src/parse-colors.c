/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:06:09 by danielji          #+#    #+#             */
/*   Updated: 2026/01/07 11:06:58 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Iterate through cub file and parse floor and ceiling colors */
void	parse_colors(t_game *g, char **arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i] && count < 2)
	{
		if (is_color(arr[i]))
		{
			trim_whitespace(arr[i]);
			if (arr[i][0] == 'F')
				parse_rgb(&arr[i][1], g->floor_color);
			else if (arr[i][0] == 'C')
				parse_rgb(&arr[i][1], g->ceiling_color);
			count++;
		}
		i++;
	}
}

/* Parse an RGB color-coded string into an array of integers */
void	parse_rgb(char *line, int color[3])
{
	int	i;
	int	value;
	int	color_index;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!is_valid_color(&line[i]))
		return ;
	color_index = 0;
	while (line[i] && color_index < 3)
	{
		value = 0;
		while (ft_isdigit(line[i]))
		{
			value *= 10;
			value += line[i] - '0';
			i++;
		}
		if (value >= 0 && value <= 255)
			color[color_index] = value;
		color_index++;
		i++;
	}
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
	return (1);
}

/* Check if line is a floor or ceiling color line */
int	is_color(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 'F' || str[i] == 'C')
		return (1);
	return (0);
}
