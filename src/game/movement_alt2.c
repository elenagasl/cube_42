/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_alt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:23:27 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/16 11:24:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

#define MARG 0.5

int	is_walkable(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->map_w || y < 0 || y >= g->map_h)
		return (0);
	return (g->map[y][x] == 0);
}

void	rotate(t_player *p, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

void	move_longitudinal(t_game *g, double speed, int dir)
{
	double	new_x;
	double	new_y;
	double	marg_x;
	double	marg_y;

	new_x = g->player.pos_x + (dir * g->player.dir_x * speed);
	new_y = g->player.pos_y + (dir * g->player.dir_y * speed);
	marg_x = dir * g->player.dir_x * MARG;
	marg_y = dir * g->player.dir_y * MARG;
	if (is_walkable(g, (int)(new_x + marg_x), (int)(g->player.pos_y)))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)(g->player.pos_x), (int)(new_y + marg_y)))
		g->player.pos_y = new_y;
/* 	if (is_walkable(g, (int)(new_x + marg_x), (int)(new_y + marg_y)))
	{
		g->player.pos_x = new_x;
		g->player.pos_y = new_y;
	} */
}

void	move_lateral(t_game *g, double speed, int dir)
{
	double	new_x;
	double	new_y;
	double	marg_x;
	double	marg_y;

	new_x = g->player.pos_x + (dir * g->player.plane_x * speed);
	new_y = g->player.pos_y + (dir * g->player.plane_y * speed);
	marg_x = dir * g->player.plane_x * MARG;
	marg_y = dir * g->player.plane_y * MARG;
	if (is_walkable(g, (int)(new_x + marg_x), (int)(g->player.pos_y)))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)(g->player.pos_x), (int)(new_y + marg_y)))
		g->player.pos_y = new_y;
/* 	if (is_walkable(g, (int)(new_x + marg_x), (int)(new_y + marg_y)))
	{
		g->player.pos_x = new_x;
		g->player.pos_y = new_y;
	} */
}

void	update_player(t_game *g)
{
	double	move_speed;
	double	rot_speed;

	move_speed = g->frame_time * 5.0;
	rot_speed = g->frame_time * 3.0;
	if (g->key_w)
		move_longitudinal(g, move_speed, 1);
	if (g->key_s)
		move_longitudinal(g, move_speed, -1);
	if (g->key_a)
		move_lateral(g, move_speed, -1);
	if (g->key_d)
		move_lateral(g, move_speed, 1);
	if (g->key_left)
		rotate(&g->player, -rot_speed);
	if (g->key_right)
		rotate(&g->player, rot_speed);
}
