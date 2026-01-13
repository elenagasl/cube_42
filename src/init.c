/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:15:11 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/13 14:51:13 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_player(t_game *g)
{
	g->player.pos_x = 0.0;
	g->player.pos_y = 0.0;
	g->player.dir_x = 0.0;
	g->player.dir_y = 0.0;
	//g->player.pos_x = 12.5;
	//g->player.pos_y = 3.5;
	//g->player.dir_x = -1.0;
	//g->player.dir_y = 0.0;
	g->player.plane_x = 0.0;
	g->player.plane_y = 0.66;
}

static void	init_image(t_game *g)
{
	g->img.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	g->img.addr = mlx_get_data_addr(
		g->img.img, &g->img.bpp,
		&g->img.line_len, &g->img.endian);
		
	int i = 0;
	while (i < 4)
	{
		g->textures[i].img = mlx_xpm_file_to_image(g->mlx, g->text_paths[i], &g->textures[i].w, &g->textures[i].h);
		if (g->textures[i].img == NULL)
		{
			// free and exit
			return ;
		}
		g->textures[i].addr = mlx_get_data_addr(g->textures[i].img, &g->textures[i].bpp, &g->textures[i].line_len, &g->textures[i].endian);
		i++;
	}
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	init_image(g);
	//g->map = get_map();
	//g->map_w = MAP_W;
	//g->map_h = MAP_H;
	//g->floor_color = rgb(80, 80, 80);
	//g->ceiling_color = rgb(120, 120, 200);
	g->color_north = rgb(200, 0, 0);
	g->color_south = rgb(0, 200, 0);
	g->color_west = rgb(0, 0, 200);
	g->color_east = rgb(200, 200, 0);
	g->key_w = 0;
	g->key_a = 0;
	g->key_s = 0;
	g->key_d = 0;
	g->key_left = 0;
	g->key_right = 0;
	g->time = get_time_in_seconds();
	g->old_time = g->time;
	g->frame_time = 0.0;
//	init_player(g);
}

void	init_parser(t_game *g)
{
	g->map = NULL;
	g->text_paths[NO] = NULL;
	g->text_paths[SO] = NULL;
	g->text_paths[WE] = NULL;
	g->text_paths[EA] = NULL;
	g->floor_color = -1.0;
	g->ceiling_color = -1.0;
	//init_int_arr(g->floor_arr, 3, -1);
	//init_int_arr(g->ceiling_arr, 3, -1);
	g->img.img = NULL;
	g->img.addr = NULL;
	g->mlx = NULL;
	g->win = NULL;
	init_player(g);
}
