/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/22 18:03:24 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Iterate through an array of strings, get map size, get player and
check whether it's a valid map surrounded by walls. On error return `0`. */
int	parse_map(t_game *g, char **arr)
{
	int		i;
	char	player;

	i = 0;
	while (!is_first_map_line(arr[i]))
		i++;
	get_map_size(g, &arr[i]);
	if (g->map_w < 3 || g->map_h < 3)
		return (printf(MAP_SIZE_INVAL"\n"), 0);
	player = get_player(g, &arr[i]);
	if (!player)
		return (0);
	normalize_map_spaces(&arr[i], g->map_h, g->map_w);
	if (!is_valid_map(&arr[i], player, g->map_h))
		return (0);
	if (!flood_fill(&arr[i], player, g->map_h))
		return (0);
	if (!map_to_int_arr(g, &arr[i], player))
		return (0);
	return (1);
}

/* Fill in with spaces every string shorter than the longest string */
void	normalize_map_spaces(char **arr, int h, int w)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < h)
	{
		if ((int)ft_strlen(arr[i]) < w)
		{
			temp = ft_calloc(w + 1, 1);
			if (!temp)
			{
				perror("Error");
				return ;
			}
			ft_memset(temp, ' ', (size_t)w);
			ft_memcpy(temp, arr[i], ft_strlen(arr[i]));
			free(arr[i]);
			arr[i] = temp;
		}
		i++;
	}
}

/* A top or bottom map line can contain `1` or spaces only */
static int	is_valid_top_bottom_line(char *str)
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

/* An in-between map line can contain `0`, `1`, player character or spaces */
static int	is_valid_map_line(char *str, char p)
{
	int	i;
	int	len;

	len = ft_strlen(str) - 1;
	while (ft_isspace(str[len]))
		len--;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '1' || str[len] != '1')
		return (0);
	while (str[i])
	{
		if (!is_char_in_set(str[i], "01") && str[i] != p && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* - Check if top and bottom map lines are valid
- Check if other map lines are valid  */
int	is_valid_map(char **arr, char player, int h)
{
	int	i;

	i = 0;
	if (!is_valid_top_bottom_line(arr[0]))
		return (printf(MAP_TOP_INVAL"\n"), 0);
	if (!is_valid_top_bottom_line(arr[h - 1]))
		return (printf(MAP_BOT_INVAL"\n"), 0);
	while (i < h)
	{
		if (!is_empty_line(arr[i]) && !is_valid_map_line(arr[i], player))
			return (printf(MAP_LINE_INVAL"\n"), 0);
		i++;
	}
	return (1);
}
