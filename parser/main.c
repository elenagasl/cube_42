/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 14:48:42 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_int_arr(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = value;
}

void	get_texture(char *line, int textures[4])
{
	int		i;
	int		fd;
	char	*path;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	path = &line[i];
	if (is_valid_extension(path, ".png"))
		fd = open_rdonly_file(path);
	if (line[0] == 'N' && textures[0] != -1)
		textures[0] = fd;
	else if (line[0] == 'S' && textures[1] != -1)
		textures[1] = fd;
	else if (line[0] == 'W' && textures[2] != -1)
		textures[2] = fd;
	else if (line[0] == 'E' && textures[3] != -1)
		textures[3] = fd;
}

void	process_metadata(char *path, char **arr, t_map *map, int map_start)
{
	int	i;

	i = 0;
	while (i < map_start)
	{
		ft_trim_whitespace(arr[i]);
		if (is_texture(arr[i]))
			get_texture(arr[i], map->textures);
		else if (arr[i][0] == 'F')
		{
			//TODO
			//get_color(arr[i], map->floor_color);
		}
		else if (arr[i][0] == 'C')
		{
			//TODO
			//get_color(arr[i], map->ceiling_color);
		}
		i++;
	}
	(void)path;
}

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
		// Exit ??
	}
	path = argv[1];
	ft_trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf("Invalid or missing file extension: only .cub files are supported\n");
		return (1);
		// Exit ??
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

	process_metadata(path, file, map, map_start);
	close(fd);
	return (0);
}
