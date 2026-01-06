/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 22:35:27 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Open .cub file, parse textures, colors and map.
On error exit program.
TODO: Free allocated memory on error ???
TODO: ON ERROR SHOULD RETURN -1 OR 0 */
void	parse_file(char *path, t_game *g)
{
	int		fd;
	char	**file;

	fd = open_cub_file(path);
	file = arr_string_from_fd(fd);
	if (!file)
		return (printf(EMPTY"\n"), exit(1));
	if (!is_valid_file(file))
		exit(1);
	parse_textures(g, file);
	parse_colors(g, file);
	if (validate_parsed_data(g))
		print_parsed_data(g);
	else
		exit(1);
	parse_map(g, file);
}

/* Open .cub file indicated in `path`. On error exit program */
int	open_cub_file(char *path)
{
	int	fd;

	trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf(INV_MAP_EXT"\n");
		exit(1);
	}
	fd = open_rdonly_file(path);
	if (fd < 0)
		exit(1);
	return (fd);
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
