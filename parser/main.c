/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 12:16:37 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
TODO: TOO MANY LINES
TODO: On error should exit program??? */
int	main(int argc, char *argv[])
{
	int		fd;
	char	*path;
	char	**file;
	int		map_start;
	t_map	*map;

	path = argv[1];
	if (!validate_arg(argc, path))
		return (1);
	fd = open_rdonly_file(path);
	if (fd < 0)
		return (1);
	file = arr_string_from_fd(fd);
	if (!file)
		return (printf("Error: Empty file\n"), 1);
	if (!validate_file(path, file, &map_start))
		return (free_arr_str(file), 1);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("malloc");
		return (1);
	}
	init_int_arr(map->textures, 4, -1);
	init_int_arr(map->ceiling_color, 3, -1);
	init_int_arr(map->floor_color, 3, -1);
	if (!parse_metadata(file, map, map_start))
		return (free_arr_str(file), free(map), 1);
	printf("Metadata validation passed! :)\n");
	parse_map(file, map, map_start);
	free_arr_str(file);
	free(map);
	return (0);
}
