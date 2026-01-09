/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 12:51:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO: Handle malloc fail
void	normalize_map_spaces(char **arr, int h, int w)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < h)
	{
		if (ft_strlen(arr[i]) < (size_t)w)
		{
			temp = malloc(sizeof(char) * w + 2);
			if (!temp)
			{
				// TODO
			}
			ft_memset(temp, ' ', w);
			ft_memcpy(temp, arr[i], w);
			temp[w]  = '\n';
			temp[w + 1]  = '\0';
			free(arr[i]);
			arr[i] = temp;
		}
		i++;
	}
}

/*
TODO: Obtener coordenadas y orientación player */
void	parse_map(t_game *g, char **arr)
{
	int		i;
	char	player;

	i = 0;
	while (!is_first_map_line(arr[i]))
		i++;
	player = get_player(&arr[i]);
	if (!player)
		return ;
	get_map_size(g, &arr[i]);
	if (g->map_w < 3 || g->map_h < 3)
	{
		printf(MAP_SIZE_INVAL"\n");
		return ;
	}
	normalize_map_spaces(&arr[i], g->map_h, g->map_w);
	if (!is_valid_map(&arr[i], player, g->map_h))
		return ;
	if (!flood_fill(&arr[i], player, g->map_h))
		return ;
	if (!map_to_int_arr(g, &arr[i], player))
		return ;
}

/* Return the `N`, `S`, `W`, or `E`  character that
represents the player's position and orientation */
char	get_player(char **arr)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	player = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (is_char_in_set(arr[i][j], "NSWE"))
			{
				if (player)
					return (printf(PLYR_MULTI"\n"), 0);
				player = arr[i][j];
			}
			j++;
		}
		i++;
	}
	if (!player)
		return (printf(PLYR_MISS"\n"), 0);
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
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (arr[i][j])
		{
			if ((arr[i][j] == '0' || arr[i][j] == p) && !is_surrounded(arr, i, j))
				return (printf("Error: Space not surrounded by wall\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
