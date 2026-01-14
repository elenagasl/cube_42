/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:00:52 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/14 10:50:31 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ARG_INVAL "Invalid argument. Usage: ./cub3d <filename>.cub"
# define FILE_EMPTY "Error: Empty file"
# define FILE_EXT "Error: Only .cub files are supported"
# define DATA_MISS "Error: Missing data"
# define DATA_DUP "Error: Duplicated data"
# define TEXT_EXT "Error: Only XPM texture files are supported"
# define TEXT_DUP "Error: Duplicated texture"
# define TEXT_MISS "Error: Missing texture file"
# define XPM_INVAL "Error: Invalid or corrupted XPM file"
# define COLOR_INVAL "Error: Missing or invalid color"
# define COLOR_RANGE "Error: Out of range color"
# define MAP_MISS "Error: Missing map"
# define MAP_TOP_INVAL "Error: Invalid map top line"
# define MAP_BOT_INVAL "Error: Invalid map bottom line"
# define MAP_LINE_INVAL "Error: Invalid map line"
# define MAP_OPEN "Error: Space not surrounded by wall"
# define MAP_SIZE_INVAL "Error: Invalid map size"
# define LINE_INVAL "Error: Invalid line"
# define LINE_UNEXP "Error: Unexpected line"
# define PLYR_MISS "Error: Missing player position"
# define PLYR_MULTI "Error: No more than one player position allowed"

#endif
