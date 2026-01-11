/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:12 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/05 17:23:14 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// free parser data
void	free_parser(t_game *g)
{
	free_textures(g->textures);
	free_arr_int(g->map, g->map_h);
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

int	exit_game(t_game *g)
{
	destroy_image(g);
	destroy_window(g);
	if (g->mlx)
		free(g->mlx);
	exit(0);
	return (0);
}
