/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/07 16:36:11 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
TODO: Medir dimensiones 
TODO: Obtener coordenadas player */
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
		printf(MAP_SIZE"\n");
		return ;
	}
	if (!is_valid_map(&arr[i], player))
		return ;
	if (!flood_fill(&arr[i]))
		return ;
	if (!map_to_int_arr(g, &arr[i], player))
		return ;
	printf("\033[1;32mMap is valid!\033[0m\n");
	//print_parsed_data(g);
}

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

/* A '0' can't be surrounded by space */
int	is_surrounded(char **arr, int x, int y)
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
}

int	flood_fill(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '0' && !is_surrounded(arr, i, j))
				return (printf("Error: Space not surrounded by wall\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
