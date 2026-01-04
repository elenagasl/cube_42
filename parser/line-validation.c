/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line-validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:34:28 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 21:34:49 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if line is a texture line */
int	is_texture(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(&str[i], "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "EA ", 3) == 0)
		return (1);
	return (0);
}

/* Check if line is a floor or ceiling color line */
int	is_color(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(&str[i], "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "C ", 2) == 0)
		return (1);
	return (0);
}

/* Check if line is the starting line of the map */
int	is_map(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}

/* Check if a line is composed of whitespace only and a new line character */
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
