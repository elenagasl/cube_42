/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:59 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 09:56:25 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Get map height */
static int	get_map_height(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	i--;
	while (is_empty_line(arr[i]))
		i--;
	return (i + 1);
}

/* Get length of the longest line */
static int	get_map_width(char **arr, int h)
{
	int	i;
	int	width;
	int	max_width;

	i = 0;
	width = 0;
	max_width = 0;
	while (i < h)
	{
		width = ft_strlen(arr[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	return (max_width);
}

/* Save map width and height into `t_game g` */
void	get_map_size(t_game *g, char **arr)
{
	g->map_h = get_map_height(arr);
	g->map_w = get_map_width(arr, g->map_h);
}
