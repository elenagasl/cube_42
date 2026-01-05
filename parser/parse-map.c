/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 16:57:23 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

int	is_valid_middle_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '1' || str[ft_strlen(str) - 1] != '1')
		return (0);
	while (str[i])
	{
		if (!is_char_in_set(str[i], "01NSWE") && !ft_isspace(str[i]))
			return (0);
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

int	validate_player(char **arr, int start, int end)
{
	int	i;
	int	j;
	int	player[4];
	int	result;

	i = start + 1;
	init_int_arr(player, 4, 0);
	while (i < end)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'N')
				player[0]++;
			else if (arr[i][j] == 'S')
				player[1]++;
			else if (arr[i][j] == 'W')
				player[2]++;
			else if (arr[i][j] == 'E')
				player[3]++;
			j++;
		}
		i++;
	}
	i = 0;
	result = 0;
	while (i < 4)
	{
		result += player[i];
		i++;
	}
	if (result == 0)
		return (printf("Error: Missing player position\n"), 0);
	else if (result > 1)
		return (printf("Error: No more than one player position allowed\n"), 0);
	return (1);
}

/* A '0' can't be surrounded by space OR NEW LINE, OR '\0', OR TAB, etc */
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

/*
TODO: Normalizar mapa (todas las líneas de la misma longitud)
TODO: Medir dimensiones 
TODO: Validar posición player
TODO: Obtener coordenadas player */
int	parse_map(char **arr, t_map *map, int start)
{
	int	i;
	int	end;

	i = start;
	if (!is_valid_top_bottom_line(arr[start]))
		return (printf("Error: Invalid map top line\n"), 0);
	i++;
	while (arr[i] && !is_empty_line(arr[i]))
	{
		ft_trim_ws_right(arr[i]);
		if (!is_valid_middle_line(arr[i]))
			return (printf("Invalid map middle line\n"), 0);
		i++;
	}
	if (i - 1 == start || !is_valid_top_bottom_line(arr[i - 1]))
		return (printf("Invalid map bottom line\n"), 0);
	end = i;
	while (arr[i])
	{
		if (!is_empty_line(arr[i]))
			return (printf("Unexpected line\n"), 0);
		i++;
	}
	if (!validate_player(arr, start, end))
		return (0);
	if (!flood_fill(arr, start, end))
		return (printf("Error: Space not surrounded by wall\n"), 0);
	(void)map;
	return (1);
}
