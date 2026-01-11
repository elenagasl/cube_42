/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:11:43 by danielji          #+#    #+#             */
/*   Updated: 2026/01/09 18:39:02 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_arr(int color[3])
{
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

int	rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

double	get_time_in_seconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}
