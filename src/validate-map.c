/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:18:46 by danielji          #+#    #+#             */
/*   Updated: 2026/01/08 12:49:53 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_map(char **arr, char player)
{
	int	i;

	i = 0;
	if (!is_valid_top_bottom_line(arr[i]))
		return (printf(MAP_TOP_INVAL"\n"), 0);
	i++;
	while (arr[i] && !is_empty_line(arr[i]))
	{
		if (!is_valid_map_line(arr[i], player))
			return (printf(MAP_LINE_INVAL"\n"), 0);
		i++;
	}
	if (!is_valid_top_bottom_line(arr[i - 1]))
		return (printf(MAP_BOT_INVAL"\n"), 0);
	while (arr[i])
	{
		if (!is_empty_line(arr[i]))
			return (printf(LINE_UNEXP"\n"), 0);
		i++;
		}
	//! Trying to validate split map
	/* 	while (arr[i])
	{
		if (!is_empty_line(arr[i]))
			return (is_valid_map(&arr[i], player));
		//else
		//	return (printf(LINE_UNEXP"\n"), 0);
		i++;
	} */
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

int	is_valid_map_line(char *str, char p)
{
	int	i;
	int	len;

	len = ft_strlen(str) - 1;
	while (ft_isspace(str[len]))
		len--;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (i == len || str[i] != '1' || str[len] != '1')
		return (0);
	while (str[i])
	{
		if (!is_char_in_set(str[i], "01") && str[i] != p && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
