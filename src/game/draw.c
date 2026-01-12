/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:43:41 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/12 20:06:47 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* static int	get_wall_color(t_game *g, t_ray *r)
{
	if (r->side == 0) // pared vertical (E / W)
	{
		if (r->ray_dx > 0)
			return (g->color_east);
		return (g->color_west);
	}
	else // pared horizontal (N / S)
	{
		if (r->ray_dy < 0)
			return (g->color_north);
		return (g->color_south);
	}
} */

/* static void	draw_colored_wall(t_game *g, int x, t_ray *r)
{
	int	color;
	int	y;

	color = get_wall_color(g, r);
	y = r->draw_start;
	while (y <= r->draw_end)
	{
		put_pixel(&g->img, x, y, color);
		y++;
	}
} */

static t_img	*get_wall_texture(t_game *g, t_ray *r)
{
	if (r->side == 0) // pared vertical (E / W)
	{
		if (r->ray_dx > 0)
			return (&g->textures[WE]);
		return (&g->textures[EA]);
	}
	else // pared horizontal (N / S)
	{
		if (r->ray_dy < 0)
			return (&g->textures[NO]);
		return (&g->textures[SO]);
	}
}

static void	draw_texture(t_game *g, int x, t_ray *r, double dist)
{
	t_img	*texture;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	texture = get_wall_texture(g, r);

	// wall hit position
	if (r->side == 0)
		wall_x = g->player.pos_x + dist * r->ray_dy;
	else
		wall_x = g->player.pos_x + dist * r->ray_dx;
	wall_x -= floor(wall_x);

	tex_x = (int)(wall_x * texture->w);

	// flip
	if (r->side == 0 && r->ray_dx > 0)
		tex_x = texture->w - tex_x - 1;
	if (r->side == 1 && r->ray_dy < 0)
		tex_x = texture->w - tex_x - 1;

	step = 1.0 * texture->h / (r->draw_end - r->draw_start);
	tex_pos = (r->draw_start - WIN_H / 2
			+ (r->draw_end - r->draw_start) / 2) * step;

	y = r->draw_start;
	while (y <= r->draw_end)
	{
		tex_y = (int)tex_pos & (texture->h - 1);
		tex_pos += step;

		color = texture->addr[tex_y * (texture->line_len / 4) + tex_x];
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

	if (dist <= 0.0001)
		return ;
	height = (int)(WIN_H / dist);
	r->draw_start = -height / 2 + WIN_H / 2;
	r->draw_end = height / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
	draw_ceiling_floor(g, x, r->draw_start, r->draw_end);
	//draw_colored_wall(g, x, r);
	draw_texture(g, x, r, dist);
}
