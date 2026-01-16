/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:00:52 by elengarc          #+#    #+#             */
/*   Updated: 2026/01/16 12:29:18 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ARG_INVAL "Error\nInvalid argument. Usage: ./cub3d <filename>.cub"
# define FILE_EMPTY "Error\nEmpty file"
# define FILE_EXT "Error\nOnly .cub files are supported"
# define DATA_MISS "Error\nMissing data"
# define DATA_DUP "Error\nDuplicated data"
# define TEXT_EXT "Error\nOnly XPM texture files are supported"
# define TEXT_DUP "Error\nDuplicated texture"
# define TEXT_MISS "Error\nMissing texture file"
# define XPM_INVAL "Error\nInvalid or corrupted XPM file"
# define COLOR_INVAL "Error\nMissing or invalid color"
# define COLOR_RANGE "Error\nOut of range color"
# define MAP_MISS "Error\nMissing map"
# define MAP_TOP_INVAL "Error\nInvalid map top line"
# define MAP_BOT_INVAL "Error\nInvalid map bottom line"
# define MAP_LINE_INVAL "Error\nInvalid map line"
# define MAP_OPEN "Error\nSpace not surrounded by wall"
# define MAP_SIZE_INVAL "Error\nInvalid map size"
# define LINE_INVAL "Error\nInvalid line"
# define LINE_UNEXP "Error\nUnexpected line"
# define PLYR_MISS "Error\nMissing player position"
# define PLYR_MULTI "Error\nNo more than one player position allowed"

#endif
