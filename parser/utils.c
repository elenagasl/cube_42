/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:28:18 by danielji          #+#    #+#             */
/*   Updated: 2026/01/04 20:28:41 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// TODO Mejor usar enum?
int	cardinal_to_index(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (2);
	else if (c == 'E')
		return (3);
	return (-1);
}

// TODO Mejor usar enum?
int	index_to_cardinal(int i)
{
	if (i == 0)
		return ('N');
	else if (i == 1)
		return ('S');
	else if (i == 2)
		return ('W');
	else if (i == 3)
		return ('E');
	return ('0');
}
