/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:12 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/12 11:08:28 by danielji         ###   ########.fr       */
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

void	destroy_image(t_game *g)
{
	if (g->img.img)
		mlx_destroy_image(g->mlx, g->img.img);
}

void	destroy_window(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
}

void	exit_game(t_game *g, int status)
{
	free_textures(g->textures);
	free_arr_int(g->map, g->map_h);
	destroy_image(g);
	destroy_window(g);
	if (g->mlx)
		free(g->mlx);
	exit(status);
}
