/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_alt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:23:27 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/15 14:00:46 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_walkable(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->map_w || y < 0 || y >= g->map_h)
		return (0);
	return (g->map[y][x] == 0);
}

int	is_pos_x_walkable(t_game *g, double new_x)
{
	double	margin;

	margin = 1.5;
	if (is_walkable(g, (int)(new_x + margin), (int)g->player.pos_y)
		&& is_walkable(g, (int)(new_x - margin), (int)g->player.pos_y))
			return (1);
	return (0);
}

int	is_pos_y_walkable(t_game *g, double new_y)
{
	double	margin;

	margin = 1.5;
	if (is_walkable(g, (int)g->player.pos_x, (int)(new_y + margin))
		&& is_walkable(g, (int)g->player.pos_x, (int)(new_y - margin)))
			return (1);
	return (0);
}

void	rotate(t_game *g, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(rot_speed)
		- g->player.dir_y * sin(rot_speed);
	g->player.dir_y = old_dir_x * sin(rot_speed)
		+ g->player.dir_y * cos(rot_speed);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(rot_speed)
		- g->player.plane_y * sin(rot_speed);
	g->player.plane_y = old_plane_x * sin(rot_speed)
		+ g->player.plane_y * cos(rot_speed);
}

void	move_lateral(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x + g->player.plane_x * speed;
	new_y = g->player.pos_y + g->player.plane_y * speed;
	if (is_pos_x_walkable(g, new_x))
		g->player.pos_x = new_x;
	if (is_pos_y_walkable(g, new_y))
		g->player.pos_y = new_y;
}

void	move_longitudinal(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x + g->player.dir_x * speed;
	new_y = g->player.pos_y + g->player.dir_y * speed;
	if (is_pos_x_walkable(g, new_x))
		g->player.pos_x = new_x;
	if (is_pos_y_walkable(g, new_y))
		g->player.pos_y = new_y;
}

/* void	update_player(t_game *g)
{
	double	move_speed;
	double	rot_speed;

	move_speed = g->frame_time * 5.0;
	rot_speed = g->frame_time * 3.0;
	if (g->key_w)
		move_longitudinal(g, move_speed);
	if (g->key_s)
		move_longitudinal(g, -move_speed);
	if (g->key_a)
		move_lateral(g, -move_speed);
	if (g->key_d)
		move_lateral(g, move_speed);
	if (g->key_left)
		rotate(g, -rot_speed);
	if (g->key_right)
		rotate(g, rot_speed);
} */

void	update_player(t_game *g)
{
	double	move_speed;
	double	rot_speed;

	move_speed = g->frame_time * 5.0;
	rot_speed = g->frame_time * 3.0;
	if (g->key_s || g->key_a)
		move_speed = -move_speed;
	if (g->key_left)
		rot_speed = -rot_speed;
	if (g->key_w || g->key_s)
		move_longitudinal(g, move_speed);
	if (g->key_a || g->key_d)
		move_lateral(g, move_speed);
	if (g->key_left || g->key_right)
		rotate(g, rot_speed);
}
