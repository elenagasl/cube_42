/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:39:00 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 00:34:04 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* Set game's player initial position and orientation according to the
passed coordinates `y` and `x`, and orientation indicated by `p` */
static void	set_player(t_game *g, int y, int x, char p)
{
	g->player.pos_x = (double)x + 0.5;
	g->player.pos_y = (double)y + 0.5;
	if (p == 'N')
	{
		g->player.dir_y = -1.0;
		g->player.plane_x = 0.66;
	}
	else if (p == 'S')
	{
		g->player.dir_y = 1.0;
		g->player.plane_x = -0.66;
	}
	else if (p == 'E')
	{
		g->player.dir_x = 1.0;
		g->player.plane_y = 0.66;
	}
	else if (p == 'W')
	{
		g->player.dir_x = -1.0;
		g->player.plane_y = -0.66;
	}
}

/* Return the `N`, `S`, `W`, or `E`  character that
represents the player's position and orientation.
Return `0` if multiple or no player found. */
char	get_player(t_game *g, char **arr)
{
	int		y;
	int		x;
	char	player;

	y = 0;
	player = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (is_char_in_set(arr[y][x], "NSWE"))
			{
				if (player)
					return (printf(PLYR_MULTI"\n"), 0);
				player = arr[y][x];
				set_player(g, y, x, player);
			}
			x++;
		}
		y++;
	}
	if (!player)
		return (printf(PLYR_MISS"\n"), 0);
	return (player);
}
