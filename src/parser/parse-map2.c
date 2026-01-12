/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/12 10:49:33 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

/* Return the `N`, `S`, `W`, or `E`  character that
represents the player's position and orientation */
char	get_player(t_game *g, char **arr)
{
	int		y;
	int		x;
	char	player;

	y = 0;
	player = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (is_char_in_set(arr[y][x], "NSWE"))
			{
				if (player)
					return (printf(PLYR_MULTI"\n"), player);
				player = arr[y][x];
				set_player(g, y, x, player);
			}
			x++;
		}
		y++;
	}
	return (player);
}

void	set_player(t_game *g, int y, int x, char p)
{
	g->player.pos_x = (double)x + 0.5;
	g->player.pos_y = (double)y + 0.5;
	if (p == 'N')
		g->player.dir_y = -1.0;
	else if (p == 'S')
		g->player.dir_y = 1.0;
	else if (p == 'E')
		g->player.dir_x = 1.0;
	else if (p == 'W')
		g->player.dir_x = -1.0;
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
					return (printf(MAP_OPEN"\n"), 0);
			}
			c++;
		}
		r++;
	}
	return (1);
}
