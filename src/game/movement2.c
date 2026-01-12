/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:58:02 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/10 16:58:03 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_walkable(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->map_w || y < 0 || y >= g->map_h)
		return (0);
	return (g->map[y][x] == 0);
}

void	move_forward(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x + g->player.dir_x * speed;
	new_y = g->player.pos_y + g->player.dir_y * speed;
	if (is_walkable(g, (int)new_x, (int)g->player.pos_y))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)g->player.pos_x, (int)new_y))
		g->player.pos_y = new_y;
}

void	move_backward(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x - g->player.dir_x * speed;
	new_y = g->player.pos_y - g->player.dir_y * speed;
	if (is_walkable(g, (int)new_x, (int)g->player.pos_y))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)g->player.pos_x, (int)new_y))
		g->player.pos_y = new_y;
}

void	move_left(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x - g->player.plane_x * speed;
	new_y = g->player.pos_y - g->player.plane_y * speed;
	if (is_walkable(g, (int)new_x, (int)g->player.pos_y))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)g->player.pos_x, (int)new_y))
		g->player.pos_y = new_y;
}

void	move_right(t_game *g, double speed)
{
	double	new_x;
	double	new_y;

	new_x = g->player.pos_x + g->player.plane_x * speed;
	new_y = g->player.pos_y + g->player.plane_y * speed;
	if (is_walkable(g, (int)new_x, (int)g->player.pos_y))
		g->player.pos_x = new_x;
	if (is_walkable(g, (int)g->player.pos_x, (int)new_y))
		g->player.pos_y = new_y;
}
