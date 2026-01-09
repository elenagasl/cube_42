/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:23:59 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 18:39:41 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Save map width and height into `t_game g`.
Spaces are taken into account, except for `\n` */
void	get_map_size(t_game *g, char **arr)
{
	g->map_h = get_map_height(arr);
	g->map_w = get_map_width(arr, g->map_h);
}

int	get_map_height(char **arr)
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

int	get_map_width(char **arr, int h)
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

// TODO: Should we call exit() after malloc fail?
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
