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

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_game(g);
	return (0);
}

int	close_window(t_game *g)
{
	exit_game(g);
	return (0);
}
