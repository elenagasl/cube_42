/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file-validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:17:49 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 20:26:54 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if line is a texture line */
int	is_texture(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(&str[i], "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "SO ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "WE ", 3) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "EA ", 3) == 0)
		return (1);
	return (0);
}

/* Check if line is a floor or ceiling color line */
int	is_color(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_strncmp(&str[i], "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(&str[i], "C ", 2) == 0)
		return (1);
	return (0);
}

/* Check if line is the starting line of the map */
int	is_map(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}

/* Check if a line is composed of whitespace only and a new line character */
int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

/* Perform a preliminary validation:
- File is not empty
- There are 7 metadata lines (nothing more, nothing less)
	- 4 texture lines
	- 2 color lines
	- 1 map starting line
- Map must be at the end
- `map_start` holds the line index at which the map starts

TODO: TOO MANY LINES*/
void	process_file(char *path, char **arr, int *map_start)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	*map_start = 0;
	if (!arr)
	{
		printf("Error: Empty file\n");
		return ;
	}
	while (arr[i])
	{
		if (is_empty_line(arr[i]))
			i++;
		else if (is_texture(arr[i]) || is_color(arr[i]))
		{
			i++;
			count++;
		}
		else if (is_map(arr[i]))
		{
			count++;
			*map_start = i;
			printf("Map starts at line %i of file '%s'\n", i + 1, path);
			break ;
		}
		else
		{
			printf("Error: Unexpected line in file"
				"%s:%i %s", path, i + 1, arr[i]);
			break ;
		}
	}
	if (count == 0)
		printf("Error: Empty file\n");
	else if (count < 7 || *map_start < 7)
		printf("Error: Missing metadata\n");
	else if (count > 7)
		printf("Error: Duplicated metadata\n");
}
