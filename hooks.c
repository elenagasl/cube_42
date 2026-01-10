/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:24:27 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/05 17:24:31 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_release(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		g->key_w = 0;
	if (keycode == KEY_S)
		g->key_s = 0;
	if (keycode == KEY_A)
		g->key_a = 0;
	if (keycode == KEY_D)
		g->key_d = 0;
	if (keycode == KEY_LEFT)
		g->key_left = 0;
	if (keycode == KEY_RIGHT)
		g->key_right = 0;
	return (0);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_game(g);
	if (keycode == KEY_W)
		g->key_w = 1;
	if (keycode == KEY_S)
		g->key_s = 1;
	if (keycode == KEY_A)
		g->key_a = 1;
	if (keycode == KEY_D)
		g->key_d = 1;
	if (keycode == KEY_LEFT)
		g->key_left = 1;
	if (keycode == KEY_RIGHT)
		g->key_right = 1;
	return (0);
}

int	close_window(t_game *g)
{
	exit_game(g);
	return (0);
}
