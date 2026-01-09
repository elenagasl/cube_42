/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:43:41 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/05 17:43:42 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_wall_color(t_game *g, t_ray *r)
{
	if (r->side == 0) // pared vertical (E / W)
	{
		if (r->ray_dx > 0)
			return (g->color_west);
		return (g->color_east);
	}
	else // pared horizontal (N / S)
	{
		if (r->ray_dy < 0)
			return (g->color_north);
		return (g->color_south);
	}
}


static void	draw_colored_wall(t_game *g, int x,
				int start, int end, t_ray *r)
{
	int	color;
	int	y;

	color = get_wall_color(g, r);
	y = start;
	while (y <= end)
	{
		put_pixel(&g->img, x, y, color);
		y++;
	}
}

void	draw_ceiling_floor(t_game *g, int x, int start, int end)
{
	int	y;

	y = 0;
	while (y < start)
	{
		put_pixel(&g->img, x, y, g->ceiling_color);
		y++;
	}
	y = end + 1;
	while (y < WIN_H)
	{
		put_pixel(&g->img, x, y, g->floor_color);
		y++;
	}
}

void	draw_wall(t_game *g, int x, double dist, t_ray *r)
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
	draw_ceiling_floor(g, x, start, end);
	draw_colored_wall(g, x, start, end, r);
}
