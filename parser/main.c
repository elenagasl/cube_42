/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 20:25:04 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Initialize an array of integers to passed `value` */
void	init_int_arr(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = value;
}

/* Parse and validate texture file descriptors and colors
TODO: Close texture file descriptors if color validation fails? */
void	process_metadata(char **arr, t_map *map, int map_start)
{
	int	i;

	i = 0;
	while (i < map_start)
	{
		ft_trim_whitespace(arr[i]);
		if (is_texture(arr[i]))
			get_texture(arr[i], map->textures);
		else if (arr[i][0] == 'F' || arr[i][0] == 'C')
			get_color(arr[i], map);
		i++;
	}
	if (!check_textures(map->textures))
		printf("Error: Missing texture file\n");
	if (!check_colors(map->floor_color))
		printf("Error: Missing or invalid floor color\n");
	if (!check_colors(map->ceiling_color))
		printf("Error: Missing or invalid ceiling color\n");
}

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

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	path = argv[1];
	ft_trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf("Invalid or missing file extension: "
			"only .cub files are supported\n");
		return (1);
	}
	fd = open_rdonly_file(path);
	file = arr_string_from_fd(fd);
	process_file(path, file, &map_start);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		perror("malloc");
		return (1);
	}
	init_int_arr(map->textures, 4, -1);
	init_int_arr(map->ceiling_color, 3, -1);
	init_int_arr(map->floor_color, 3, -1);
	process_metadata(file, map, map_start);
	close(fd);
	free_arr_str(file);
	free(map);
	return (0);
}
