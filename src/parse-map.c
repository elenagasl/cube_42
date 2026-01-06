/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 20:33:41 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
TODO: Normalizar mapa (todas las líneas de la misma longitud)
TODO: Medir dimensiones 
TODO: Validar posición player
TODO: Obtener coordenadas player */
void	parse_map(t_game *g, char **arr)
{
	int		i;
	char	player;

	i = 0;
	while (!is_first_map_line(arr[i]))
		i++;
	player = get_player(&arr[i]);
	if (player && is_valid_map(&arr[i], player))
		printf("Map is valid!\n");
	
	
	(void)g;

/*
	if (!flood_fill(arr, start, end))
		return (printf("Error: Space not surrounded by wall\n"), 0); */
}

int	is_valid_map(char **arr, char player)
{
	int	i;

	i = 0;
	if (!is_valid_top_bottom_line(arr[i]))
		return (printf("Error: Invalid map top line\n"), 0);
	i++;
	while (arr[i] && !is_empty_line(arr[i]))
	{
		if (!is_valid_map_line(arr[i], player))
			return (printf("Error: Invalid map line\n"), 0);
		i++;
	}
	if (!is_valid_top_bottom_line(arr[i - 1]))
		return (printf("Error: Invalid map bottom line\n"), 0);
	while (arr[i])
	{
		if (!is_empty_line(arr[i]))
			return (printf("Error: Unexpected line\n"), 0);
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

int	is_valid_map_line(char *str, char p)
{
	int		i;
	int		len;

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

char	get_player(char **arr)
{
	int		i;
	int		j;
	char	c;
	char	player;

	i = 0;
	player = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			c = arr[i][j];
			if (is_char_in_set(c, "NSWE"))
			{
				if (player)
				{
					printf("Error: No more than one player position allowed\n");
					return (0);
				}
				player = c;
			}
			j++;
		}
		i++;
	}
	if (!player)
		return (printf("Error: Missing player position\n"), 0);
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

/* 
// A '0' can't be surrounded by space OR NEW LINE, OR '\0', OR TAB, etc
// TODO: ¡Cuidado! Al hacer trim los espacios han desaparecido
int	is_surrounded(char **arr, int x, int y)
{
	if (arr[x - 1][y - 1] == ' '
		|| arr[x][y - 1] == ' '
		|| arr[x + 1][y - 1] == ' '
		|| arr[x - 1][y] == ' '
		|| arr[x + 1][y] == ' '
		|| arr[x - 1][y + 1] == ' '
		|| arr[x][y + 1] == ' '
		|| arr[x + 1][y + 1] == ' ')
		return (0);
	return (1);
}

int	flood_fill(char **arr, int start, int end)
{
	int	i;
	int	j;

	i = start + 1;
	while (i < end)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '0' && !is_surrounded(arr, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
 */
