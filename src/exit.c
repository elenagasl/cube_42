/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:12 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 10:42:13 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_textures(char **arr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	arr = NULL;
}

void	free_arr_int(int **arr, int size)
{
	if (!arr)
		return ;
	while (size)
		free(arr[--size]);
	free(arr);
	arr = NULL;
}

void	free_parser(t_game *g)
{
	free_textures(g->text_paths);
	free_arr_int(g->map, g->map_h);
}

void	destroy_images(t_game *g)
{
	if (g->img.img)
		mlx_destroy_image(g->mlx, g->img.img);
	if (g->textures[NO].img)
		mlx_destroy_image(g->mlx, g->textures[NO].img);
	if (g->textures[SO].img)
		mlx_destroy_image(g->mlx, g->textures[SO].img);
	if (g->textures[WE].img)
		mlx_destroy_image(g->mlx, g->textures[WE].img);
	if (g->textures[EA].img)
		mlx_destroy_image(g->mlx, g->textures[EA].img);
}

/* void	destroy_window(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
} */

void	exit_game(t_game *g, int status)
{
	free_parser(g);
	destroy_images(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
		free(g->mlx);
	exit(status);
}
