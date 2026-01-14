/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:43:41 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 16:27:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

/* Select which texture should be rendered
according to which wall is facing the player */
static t_img	*get_wall_texture(t_game *g, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->ray_dx > 0)
			return (&g->textures[WE]);
		return (&g->textures[EA]);
	}
	else
	{
		if (r->ray_dy < 0)
			return (&g->textures[SO]);
		return (&g->textures[NO]);
	}
}

void	draw_wall(t_game *g, int x, t_ray *r)
{
	t_img	*texture;
	int		height;

	if (r->dist <= 0.0001)
		return ;
	texture = get_wall_texture(g, r);
	height = (int)(WIN_H / r->dist);
	r->draw_start = -height / 2 + WIN_H / 2;
	r->draw_end = height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end > WIN_H)
		r->draw_end = WIN_H - 1;
	r->line_height = height;
	draw_ceiling_floor(g, x, r->draw_start, r->draw_end);
	draw_texture_column(g, texture, x, r);
}
