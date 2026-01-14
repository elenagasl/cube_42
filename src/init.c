/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:15:11 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 16:34:18 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player(t_game *g)
{
	g->player.pos_x = 0.0;
	g->player.pos_y = 0.0;
	g->player.dir_x = 0.0;
	g->player.dir_y = 0.0;
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.0;
}

static void	init_images(t_game *g)
{
	int	i;

	g->img.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->img.addr = mlx_get_data_addr(
			g->img.img, &g->img.bpp,
			&g->img.line_len, &g->img.endian);
	i = 0;
	while (i < 4)
	{
		g->textures[i].img = mlx_xpm_file_to_image(
				g->mlx, g->text_paths[i],
				&g->textures[i].w, &g->textures[i].h);
		if (g->textures[i].img == NULL)
		{
			printf(XPM_INVAL"\n");
			exit_game(g, 1);
		}
		g->textures[i].addr = mlx_get_data_addr(
				g->textures[i].img, &g->textures[i].bpp,
				&g->textures[i].line_len, &g->textures[i].endian);
		i++;
	}
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	init_images(g);
	g->key_w = 0;
	g->key_a = 0;
	g->key_s = 0;
	g->key_d = 0;
	g->key_left = 0;
	g->key_right = 0;
	g->time = get_time_in_seconds();
	g->old_time = g->time;
	g->frame_time = 0.0;
}

void	init_parser(t_game *g)
{
	int	i;

	g->map = NULL;
	g->floor_color = -1;
	g->ceiling_color = -1;
	g->img.img = NULL;
	g->img.addr = NULL;
	g->mlx = NULL;
	g->win = NULL;
	i = 0;
	while (i < 4)
	{
		g->text_paths[i] = NULL;
		g->textures[i].img = NULL;
		g->textures[i].addr = NULL;
		i++;
	}
	init_player(g);
}
