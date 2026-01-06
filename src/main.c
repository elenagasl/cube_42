/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:27:06 by danielji          #+#    #+#             */
/*   Updated: 2026/01/06 16:58:56 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_parse_data(t_game *g)
{
	g->textures[0] = NULL;
	g->textures[1] = NULL;
	g->textures[2] = NULL;
	g->textures[3] = NULL;
	init_int_arr(g->floor_color, 3, -1);
	init_int_arr(g->ceiling_color, 3, -1);
}

int	main(int argc, char *argv[])
{
	t_game	g;

	if (argc != 2)
		return (printf("Invalid arguments\n"), 1);
	init_parse_data(&g);
	parse_file(argv[1], &g);

	//init_game(&g);
	//render_frame(&g);
	//mlx_loop(g.mlx);
	return (0);
}
