/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw-texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:48:10 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 12:29:37 by danielji         ###   ########.fr       */
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

double	get_wall_x(t_game *g, t_ray *r, double dist)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = g->player.pos_y + dist * r->ray_dy;
	else
		wall_x = g->player.pos_x + dist * r->ray_dx;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_tex_y(double tex_pos, int tex_h)
{
	int	tex_y;

	tex_y = (int)tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex_h)
		tex_y = tex_h - 1;
	return (tex_y);
}

// Voltear horizontalmente
int	flip_tex_x(int tex_x, t_ray *r, int tex_width)
{
	int	f_tex_x;

	f_tex_x = tex_x;
	if (r->side == 0 && r->ray_dx < 0)
		f_tex_x = tex_width - tex_x - 1;
	if (r->side == 1 && r->ray_dy > 0)
		f_tex_x = tex_width - tex_x - 1;
	return (f_tex_x);
}

void	draw_texture_column(t_game *g, t_img *t, int x, double dist, t_ray *r)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = 1.0 * t->h / r->line_height;
	tex_pos = (r->draw_start - WIN_H / 2 + r->line_height / 2) * step;

	y = r->draw_start;
	// clip top
	if (y < 0)
	{
		tex_pos += (-y) * step;
		y = 0;
	}

	tex_x = (int)(get_wall_x(g, r, dist) * t->w);
	tex_x = flip_tex_x(tex_x, r, t->w);
	while (y <= r->draw_end)
	{
		tex_y = get_tex_y(tex_pos, t->h);
		tex_pos += step;
		put_pixel(&g->img, x, y, get_tex_color(t, tex_x, tex_y));
		y++;
	}
}

/* 

void	draw_texture_column(t_game *g, int x, double dist, t_ray *r)
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

*/
