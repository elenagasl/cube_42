/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:16:04 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/04 13:16:05 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	in_bounds(t_game *g, t_ray *r)
{
	if (r->map_x < 0 || r->map_x >= g->map_w)
		return (0);
	if (r->map_y < 0 || r->map_y >= g->map_h)
		return (0);
	return (1);
}

int	perform_dda(t_game *g, t_ray *r)
{
	while (1)
	{
		if (r->side_x < r->side_y)
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (!in_bounds(g, r))
			return (0);
		if (g->map[r->map_y][r->map_x] > 0)
			return (1);
	}
}

double	get_perp_dist(t_game *g, t_ray *r)
{
	if (r->side == 0)
		return ((r->map_x - g->player.pos_x
				+ (1 - r->step_x) / 2.0) / r->ray_dx);
	return ((r->map_y - g->player.pos_y
			+ (1 - r->step_y) / 2.0) / r->ray_dy);
}

void	cast_column(t_game *g, int x)
{
	t_ray	r;
	double	dist;

	init_ray(g, &r, x);
	init_dda(g, &r);
	if (!perform_dda(g, &r))
		return ;
	dist = get_perp_dist(g, &r);
	draw_wall(g, x, dist, &r);
}
