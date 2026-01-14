/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:43:41 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 11:02:00 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

static int	get_tex_color(t_img *t, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = t->addr + (y * t->line_len + x * (t->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

static void	draw_texture_column(t_game *g, int x, double dist, t_ray *r)
{
	t_img	*t;
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	double	wall_x;

	t = get_wall_texture(g, r);

	step = 1.0 * t->h / r->line_height;
	tex_pos = (r->draw_start - WIN_H / 2 + r->line_height / 2) * step;
	y = r->draw_start;

	// clip top
	if (y < 0)
	{
		tex_pos += (-y) * step;
		y = 0;
	}

	if (r->side == 0)
		wall_x = g->player.pos_y + dist * r->ray_dy;
	else
		wall_x = g->player.pos_x + dist * r->ray_dx;
	
	wall_x -= floor(wall_x);
	
	tex_x = (int)(wall_x * t->w);

	// Voltear horizontalmente
	if (r->side == 0 && r->ray_dx < 0)
		tex_x = t->w - tex_x - 1;
	if (r->side == 1 && r->ray_dy > 0)
		tex_x = t->w - tex_x - 1;

	while (y <= r->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;

		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= t->h)
			tex_y = t->h - 1;

		put_pixel(&g->img, x, y, get_tex_color(t, tex_x, tex_y));
		y++;
	}
}

void	draw_wall(t_game *g, int x, double dist, t_ray *r)
{
	int	height;

	if (dist <= 0.0001)
		return ;
	height = (int)(WIN_H / dist);
	r->draw_start = -height / 2 + WIN_H / 2;
	r->draw_end = height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end > WIN_H)
		r->draw_end = WIN_H - 1;
	r->line_height = height;
	draw_ceiling_floor(g, x, r->draw_start, r->draw_end);
	draw_texture_column(g, x, dist, r);
}
