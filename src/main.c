/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:01:11 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 11:07:28 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	game_loop(t_game *g)
{
	g->old_time = g->time;
	g->time = get_time_in_seconds();
	g->frame_time = g->time - g->old_time;
	update_player(g);
	render_frame(g);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	g;

	parser(&g, argc, argv[1]);
	init_game(&g);
	print_parsed_data(&g);
	render_frame(&g);
	mlx_hook(g.win, 2, 1L << 0, key_press, &g);
	mlx_hook(g.win, 3, 1L << 1, key_release, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
	mlx_loop_hook(g.mlx, game_loop, &g);
	mlx_loop(g.mlx);
	exit_game(&g, 0);
	return (0);
}
