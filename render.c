/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:16:25 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/04 13:16:26 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_frame(t_game *g)
{
	int	x;

	x = 0;
	while (x < WIN_W)
	{
		cast_column(g, x);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_vertical_line(t_game *g, int x, int start, int end)
{
	int	color;

	color = rgb(200, 0, 0);
	while (start <= end)
	{
		put_pixel(&g->img, x, start, color);
		start++;
	}
}

void	draw_wall(t_game *g, int x, double dist, int side)
{
	int	height;
	int	start;
	int	end;

	if (dist <= 0.0001)
		return ;
	height = (int)(WIN_H / dist);
	start = -height / 2 + WIN_H / 2;
	end = height / 2 + WIN_H / 2;
	if (start < 0)
		start = 0;
	if (end >= WIN_H)
		end = WIN_H - 1;
	if (side == 1)
		draw_vertical_line(g, x, start + 1, end);
	else
		draw_vertical_line(g, x, start, end);
}
