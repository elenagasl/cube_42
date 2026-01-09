/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 18:21:51 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		return (printf(PLYR_MISS"\n"), 0);
	normalize_map_spaces(&arr[i], g->map_h, g->map_w);
	if (!is_valid_map(&arr[i], player, g->map_h))
		return (0);
	if (!flood_fill(&arr[i], player, g->map_h))
		return (0);
	if (!map_to_int_arr(g, &arr[i], player))
		return (0);
	return (1);
}

// TODO Obtener orientación player
/* Return the `N`, `S`, `W`, or `E`  character that
represents the player's position and orientation */
char	get_player(t_game *g, char **arr)
{
	int		r;
	int		c;
	char	player;

	r = 0;
	player = 0;
	while (arr[r])
	{
		c = 0;
		while (arr[r][c])
		{
			if (is_char_in_set(arr[r][c], "NSWE"))
			{
				if (player)
					return (printf(PLYR_MULTI"\n"), 0);
				player = arr[r][c];
				g->player.pos_x = (double)c;
				g->player.pos_y = (double)r;
			}
			c++;
		}
		r++;
	}
	return (player);
}

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

/* A `0` can't be orthogonally surrounded by space */
int	is_surrounded(char **arr, int r, int c)
{
	if (ft_isspace(arr[r + 1][c]) ||
		ft_isspace(arr[r - 1][c]) ||
		ft_isspace(arr[r][c + 1]) ||
		ft_isspace(arr[r][c - 1]))
		return (0);
	return (1);
}

/* STRICT VERSION */
/* A `0` can't be orthogonally or diagonally surrounded by space */
/* int	is_surrounded(char **arr, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (ft_isspace(arr[x + i][y + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
} */

int	flood_fill(char **arr, char p, int h)
{
	int	r;
	int	c;

	r = 0;
	while (r < h)
	{
		c = 0;
		while (arr[r][c])
		{
			if ((arr[r][c] == '0' || arr[r][c] == p))
			{
				if (!is_surrounded(arr, r, c))
					return (printf(MAP_OPEN" at %s\n", arr[r]), 0);
			}
			c++;
		}
		r++;
	}
	return (1);
}
