/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:16:25 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/13 13:05:41 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	get_tex_color(t_img *t, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = t->addr + (y * t->line_len + x * (t->bpp / 8));

	color = *(unsigned int *)pixel;
	return (color);
}

/* static void	draw_texture_fullscreen(t_game *g)
{
	int	x;
	int	y;
	int	color;
	int	tex_x;
	int	tex_y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			// scale screen -> texture
			tex_x = x * g->textures[0].w / WIN_W;
			tex_y = y * g->textures[0].h / WIN_H;
			color = get_tex_color(&g->textures[0], tex_x, tex_y);
			put_pixel(&g->img, x, y, color);
			x++;
		}
		y++;
	}
} */

/* static void	draw_texture_raw(t_game *g)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < g->textures[0].h && y < WIN_H)
	{
		x = 0;
		while (x < g->textures[0].w && x < WIN_W)
		{
			color = get_tex_color(&g->textures[0], x, y);
			put_pixel(&g->img, x, y, color);
			x++;
		}
		y++;
	}
} */

static void	draw_texture_centered(t_game *g)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = (WIN_W - g->textures[0].w) / 2;
	start_y = (WIN_H - g->textures[0].h) / 2;
	

	y = 0;
	while (y < g->textures[0].h)
	{
		x = 0;
		while (x < g->textures[0].w)
		{
			put_pixel(&g->img, start_x + x, start_y + y, get_tex_color(&g->textures[0], x, y));
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *g)
{
/* 	int	x;

	x = 0;
	while (x < WIN_W) //Recorremos pixeles por columnas
	{
		cast_column(g, x);
		x++;
	} */
	//draw_texture_fullscreen(g);
	//draw_texture_raw(g);
	draw_texture_centered(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
