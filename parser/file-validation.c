/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file-validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:17:49 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 21:37:36 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

static void	print_file_status(int i, char *path, int count, int map_start)
{
	if (count == 0)
		printf("Error: Empty file\n");
	else if (count < 7 || map_start < 7)
		printf("Error: Missing metadata\n");
	else if (count > 7)
		printf("Error: Duplicated metadata\n");
	else if (map_start >= 7)
		printf("Map starts at line %i of file '%s'\n", i + 1, path);
}

/* Perform a preliminary validation:
- File is not empty
- There are 7 metadata lines (nothing more, nothing less)
	- 4 texture lines
	- 2 color lines
	- 1 map starting line
- Map must be at the end
- `map_start` holds the line index at which the map starts*/
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
	while (arr[i] && *map_start == 0)
	{
		if (is_empty_line(arr[i]))
			i++;
		else if (is_texture(arr[i]) || is_color(arr[i]) || is_map(arr[i]))
			count_lines(arr[i], &i, &count, map_start);
		else
		{
			printf("Error: Unexpected line in file"
				"%s:%i %s", path, i + 1, arr[i]);
			break ;
		}
	}
	print_file_status(i, path, count, *map_start);
}
