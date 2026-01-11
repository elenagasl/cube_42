/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:22:27 by danielji          #+#    #+#             */
/*   Updated: 2026/01/11 18:56:16 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_mini_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map_h)
	{
		j = 0;
		while (j < g->map_w)
		{
			if ((g->map[i][j]) <= 0)
				printf("  ");
			else if ((g->map[i][j]) == 1)
				printf("\033[41m🧱\033[0m");
			else if ((g->map[i][j]) == 2)
			{
				printf("😃");
				g->map[i][j] = 0;
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

/* For debug purposes only */
void	print_parsed_data(t_game *g)
{
	printf("\033[1;32mMap is valid!\033[0m\n");
	printf("-------------------------------------\n");
	printf("North texture: %s\n", g->textures[0]);
	printf("South texture: %s\n", g->textures[1]);
	printf(" West texture: %s\n", g->textures[2]);
	printf(" East texture: %s\n", g->textures[3]);
	printf("  Floor color: %08d\n", g->floor_color);
	printf("Ceiling color: %08d\n", g->ceiling_color);
	printf("     Map size: %d x %d \n\n", g->map_w, g->map_h);
	if (g->map_w <= 50)
		print_mini_map(g);
	printf("-------------------------------------\n");
}
