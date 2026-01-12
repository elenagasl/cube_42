/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:12 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/12 10:47:48 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
