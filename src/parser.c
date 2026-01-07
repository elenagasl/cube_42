/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/07 10:46:01 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Open .cub file, parse textures, colors and map.
On error exit program.
TODO: Free allocated memory on error ???
TODO: ON ERROR SHOULD RETURN -1 OR 0 */
void	parse_file(t_game *g, char *path)
{
	int		fd;
	char	**arr;

	fd = open_cub_file(path);
	arr = arr_string_from_fd(fd);
	if (!arr || !is_valid_file(arr))
	{
		printf(EMPTY"\n");
		free_parsed_data(g, arr);
		return ;
	}
	parse_textures(g, arr);
	parse_colors(g, arr);
	if (validate_parsed_data(g))
	{
		parse_map(g, arr);
	}
	free_parsed_data(g, arr);
}

/* Open .cub file indicated in `path` and return file descriptor */
int	open_cub_file(char *path)
{
	int	fd;

	trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf(INV_MAP_EXT"\n");
		return (-1);
	}
	fd = open_rdonly_file(path);
	return (fd);
}

void	free_parsed_data(t_game *g, char **arr)
{

	if (g->textures[0] != NULL)
		free(g->textures[0]);
	if (g->textures[1] != NULL)
		free(g->textures[1]);
	if (g->textures[2] != NULL)
		free(g->textures[2]);
	if (g->textures[3] != NULL)
		free(g->textures[3]);
	g->textures[0] = NULL;
	g->textures[1] = NULL;
	g->textures[2] = NULL;
	g->textures[3] = NULL;
	free_arr_str(arr);
}

/* For debug purposes only */
void	print_parsed_data(t_game *g)
{
	printf("----------------------------------\n");
	printf("North texture: %s\n", g->textures[0]);
	printf("South texture: %s\n", g->textures[1]);
	printf(" West texture: %s\n", g->textures[2]);
	printf(" East texture: %s\n", g->textures[3]);
	printf("  Floor color: %d,%d,%d\n",
		g->floor_color[0], g->floor_color[1], g->floor_color[2]);
	printf("Ceiling color: %d,%d,%d\n",
		g->ceiling_color[0], g->ceiling_color[1], g->ceiling_color[2]);
	printf("----------------------------------\n");
}
