/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 14:47:55 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	is_valid_middle_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '1' || str[ft_strlen(str) - 1] != '1')
		return (0);
	while (str[i])
	{
		if (!is_char_in_set(str[i], "01NSWE") && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_top_bottom_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_map(char **arr, t_map *map, int start)
{
	int	i;

	i = start;
	if (!is_valid_top_bottom_line(arr[start]))
		return (printf("Error: Invalid map top line\n"), 0);
	i++;
	while (arr[i] && !is_empty_line(arr[i]))
	{
		ft_trim_ws_right(arr[i]);
		if (!is_valid_middle_line(arr[i]))
			return (printf("Invalid map middle line\n"), 0);
		i++;
	}
	if (i - 1 == start || !is_valid_top_bottom_line(arr[i - 1]))
		return (printf("Invalid map bottom line\n"), 0);
	while (arr[i])
	{
		if (!is_empty_line(arr[i]))
			return (printf("Unexpected line\n"), 0);
		i++;
	}
	(void)map;
	return (1);
}
