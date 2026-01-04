/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:10:56 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 23:24:04 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Parse and validate texture file descriptors and colors
TODO: Close texture file descriptors if color validation fails? */
int	parse_metadata(char **arr, t_map *map, int map_start)
{
	int	i;

	i = 0;
	while (i < map_start)
	{
		ft_trim_whitespace(arr[i]);
		if (is_texture(arr[i]))
			parse_texture(arr[i], map->textures);
		else if (arr[i][0] == 'F' || arr[i][0] == 'C')
			parse_color(arr[i], map);
		i++;
	}
	if (!check_textures(map->textures))
		return (printf("Error: Missing texture file\n"), 0);
	if (!check_colors(map->floor_color))
		return (printf("Error: Missing or invalid floor color\n"), 0);
	if (!check_colors(map->ceiling_color))
		return (printf("Error: Missing or invalid ceiling color\n"), 0);
	return (1);
}
