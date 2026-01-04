/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:48:20 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 23:29:34 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if `path` ends with indicated extension `ext`.
Extension must begin with dot: `.cub`, `.png`, etc. */
int	is_valid_extension(char *path, char *ext)
{
	char	*path_ext;
	size_t	len;

	path_ext = ft_strrchr(path, '.');
	len = ft_strlen(ext);
	if (!path_ext)
		return (0);
	if (ft_strlen(path_ext) != len)
		return (0);
	if (ft_strncmp(path_ext, ext, len) != 0)
		return (0);
	return (1);
}

/* Check that program argument is a path to a .cub file */
int	validate_arg(int argc, char *path)
{
	if (argc != 2)
	{
		printf("Invalid arguments. Run ./cub3d bla bla bla\n");
		return (0);
	}
	ft_trim_whitespace(path);
	if (!is_valid_extension(path, ".cub"))
	{
		printf("Invalid or missing file extension: "
			"only .cub files are supported\n");
		return (0);
	}
	return (1);
}
