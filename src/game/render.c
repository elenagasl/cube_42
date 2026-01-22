/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:16:25 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/22 18:05:45 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
