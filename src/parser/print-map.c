/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:22:27 by danielji          #+#    #+#             */
/*   Updated: 2026/01/14 11:08:17 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	print_direction(t_game *g)
{
	if (g->player.dir_x > 0)
		printf("➡️ ");
	else if (g->player.dir_x < 0)
		printf("⬅️ ");
	else if (g->player.dir_y > 0)
		printf("⬇️ ");
	else if (g->player.dir_y < 0)
		printf("⬆️ ");
}

static void	print_mini_map(t_game *g)
{
	int	y;
	int	x;
	int	px;
	int	py;

	px = (int)g->player.pos_x;
	py = (int)g->player.pos_y;
	y = 0;
	while (y < g->map_h)
	{
		x = 0;
		while (x < g->map_w)
		{
			if (y == py && x == px)
				print_direction(g);
			else if (g->map[y][x] == 1)
				printf("\033[41m🧱\033[0m");
			else
				printf("  ");
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

/* Print summary and mini map in terminal.
Print maps only smaller than 50 units wide */
void	print_parsed_data(t_game *g)
{
	printf("North texture: %s\n", g->text_paths[NO]);
	printf("South texture: %s\n", g->text_paths[SO]);
	printf(" West texture: %s\n", g->text_paths[WE]);
	printf(" East texture: %s\n", g->text_paths[EA]);
	printf("  Floor color: %08d\n", g->floor_color);
	printf("Ceiling color: %08d\n", g->ceiling_color);
	printf("     Map size: %d x %d \n\n", g->map_w, g->map_h);
	if (g->map_w <= 50)
		print_mini_map(g);
}
