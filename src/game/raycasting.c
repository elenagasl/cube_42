/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:15:51 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/04 13:15:52 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static double	get_delta(double ray)
{
	if (ray == 0.0)
		return (1e30);
	return (fabs(1.0 / ray));
}

void	init_ray(t_game *g, t_ray *r, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)WIN_W - 1.0;
	r->ray_dx = g->player.dir_x + g->player.plane_x * camera_x;
	r->ray_dy = g->player.dir_y + g->player.plane_y * camera_x;
	r->map_x = (int)g->player.pos_x;
	r->map_y = (int)g->player.pos_y;
	r->delta_x = get_delta(r->ray_dx);
	r->delta_y = get_delta(r->ray_dy);
}

static void	init_side_x(t_game *g, t_ray *r)
{
	if (r->ray_dx < 0)
	{
		r->step_x = -1;
		r->side_x = (g->player.pos_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (r->map_x + 1.0 - g->player.pos_x) * r->delta_x;
	}
}

static void	init_side_y(t_game *g, t_ray *r)
{
	if (r->ray_dy < 0)
	{
		r->step_y = -1;
		r->side_y = (g->player.pos_y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (r->map_y + 1.0 - g->player.pos_y) * r->delta_y;
	}
}

void	init_dda(t_game *g, t_ray *r)
{
	init_side_x(g, r);
	init_side_y(g, r);
}
