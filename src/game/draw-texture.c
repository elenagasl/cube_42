/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw-texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:48:10 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 16:28:38 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Calculate the color of a pixel in the given texture */
static int	get_tex_color(t_img *t, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = t->addr + (y * t->line_len + x * (t->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

/* Turn a texture position into a safe `y` coordinate, clamping if
necessary to avoid values below `0` or larger than the texture's height */
static int	get_tex_y(double tex_pos, int tex_h)
{
	int	tex_y;

	tex_y = (int)tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex_h)
		tex_y = tex_h - 1;
	return (tex_y);
}

/* Flip the texture column horizontally only if
the wall is viewed from the opposite side */
static void	flip_tex_x(int *tex_x, t_ray *r, int tex_width)
{
	if (r->side == 0 && r->ray_dx < 0)
		*tex_x = tex_width - *tex_x - 1;
	if (r->side == 1 && r->ray_dy > 0)
		*tex_x = tex_width - *tex_x - 1;
}

/* Calculate which vertical column of the
texture should be used for the wall */
static int	get_tex_x(t_game *g, t_ray *r, int tex_width)
{
	int		tex_x;
	double	wall_x;

	if (r->side == 0)
		wall_x = g->player.pos_y + r->dist * r->ray_dy;
	else
		wall_x = g->player.pos_x + r->dist * r->ray_dx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex_width);
	flip_tex_x(&tex_x, r, tex_width);
	return (tex_x);
}

/* Draw one vertical textured wall on the screen */
void	draw_texture_column(t_game *g, t_img *t, int x, t_ray *r)
{
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	step = 1.0 * t->h / r->line_height;
	tex_pos = (r->draw_start - WIN_H / 2 + r->line_height / 2) * step;
	y = r->draw_start;
	if (y < 0) // clip top
	{
		tex_pos += (-y) * step;
		y = 0;
	}
	tex_x = get_tex_x(g, r, t->w);
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
