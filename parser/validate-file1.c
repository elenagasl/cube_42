/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-file1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:17:49 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 15:30:59 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Perform a preliminary validation:
- File is not empty
- There are 7 metadata lines (nothing more, nothing less)
	- 4 texture lines
	- 2 color lines
	- 1 map starting line
- Map must be at the end
- `map_start` holds the line index at which the map starts*/
int	validate_file(char *path, char **arr, int *map_start)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	*map_start = 0;
	while (arr[i] && *map_start == 0)
	{
		if (is_empty_line(arr[i]))
			i++;
		else if (is_texture(arr[i]) || is_color(arr[i]) || is_map(arr[i]))
		{
			if (is_color(arr[i]) && !validate_color(arr[i]))
				return (printf("Error: Invalid color format"), 0);
			count_lines(arr[i], &i, &count, map_start);
		}
		else
		{
			printf("Error: Unexpected line in file"
				"%s:%i %s", path, i + 1, arr[i]);
			break ;
		}
	}
	return (file_validation_status(count, *map_start));
}

/* Update line count and `map_start` index */
void	count_lines(char *line, int *i, int *count, int *map_start)
{
	if (is_texture(line) || is_color(line))
	{
		*i += 1;
		*count += 1;
	}
	else if (is_map(line))
	{
		*count += 1;
		*map_start = *i;
	}
}

/* Display error message according to total line count and `map_start` index
Return `1` if no errors found */
int	file_validation_status(int count, int map_start)
{
	if (count == 0)
	{
		printf("Error: Empty file or missing data\n");
		return (0);
	}
	else if (count < 7 || map_start < 6)
	{
		printf("Error: Missing data\n");
		return (0);
	}
	else if (count > 7)
	{
		printf("Error: Duplicated data\n");
		return (0);
	}
	return (1);
}
