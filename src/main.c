/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/08 11:41:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_parse_data(t_game *g)
{
	g->map = NULL;
	g->textures[0] = NULL;
	g->textures[1] = NULL;
	g->textures[2] = NULL;
	g->textures[3] = NULL;
	init_int_arr(g->floor_color, 3, -1);
	init_int_arr(g->ceiling_color, 3, -1);
}

void	free_cub3d(t_game *g)
{
	free_textures(g->textures);
	free_arr_int(g->map, g->map_h);
}

int	main(int argc, char *argv[])
{
	t_game	g;

	if (argc != 2)
		return (printf(ARG_INVAL"\n"), 1);
	init_parse_data(&g);
	if (parser(&g, argv[1]))
		print_parsed_data(&g);
	else
		return (free_cub3d(&g), 1);
	//init_game(&g);
	//render_frame(&g);
	//mlx_loop(g.mlx);
	free_cub3d(&g);
	return (0);
}
