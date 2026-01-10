/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:23:27 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/10 16:23:30 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_game *g, double rot_speed)
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

void	rotate_right(t_game *g, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-rot_speed)
		- g->player.dir_y * sin(-rot_speed);
	g->player.dir_y = old_dir_x * sin(-rot_speed)
		+ g->player.dir_y * cos(-rot_speed);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-rot_speed)
		- g->player.plane_y * sin(-rot_speed);
	g->player.plane_y = old_plane_x * sin(-rot_speed)
		+ g->player.plane_y * cos(-rot_speed);
}

void	update_player(t_game *g)
{
	double	move_speed;
	double	rot_speed;

	move_speed = g->frame_time * 5.0;
	rot_speed = g->frame_time * 3.0;
	if (g->key_w)
		move_forward(g, move_speed);
	if (g->key_s)
		move_backward(g, move_speed);
	if (g->key_a)
		move_left(g, move_speed);
	if (g->key_d)
		move_right(g, move_speed);
	if (g->key_left)
		rotate_left(g, rot_speed);
	if (g->key_right)
		rotate_right(g, rot_speed);
}
