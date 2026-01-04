/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate-color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:53:20 by danielji          #+#    #+#             */
/*   Updated: 2026/01/05 00:13:40 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Check if a line is a valid color line:
- 'F' or 'C' may be followed by whitespace
- There are only 3 numbers
- Numbers are less than four digits long
- Each number is separated by a single comma */
int	validate_color(char *line)
{
	int	i;
	int	commas;
	int	digits;

	i = 0;
	commas = 0;
	digits = 0;
	ft_trim_whitespace(line);
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	while (ft_isspace(line[i]))
		i++;
	while (line[i] && line[i])
	{
		if (line[i] == ',' && !restart_comma(line[i + 1], &commas, &digits))
			return (0);
		else if (ft_isdigit(line[i]))
			digits++;
		else if (!ft_isdigit(line[i]) && line[i] != ',')
			return (0);
		i++;
	}
	if (commas != 2 || digits == 0 || digits > 3)
		return (0);
	return (1);
}

/* The character after a comma must be a digit.
After finding a comma, `digits` count should be between 1 and 3.
Restart `digits` count */
int	restart_comma(char next_char, int *commas, int *digits)
{
	if (!ft_isdigit(next_char) && next_char != '\0')
		return (0);
	if (*digits == 0 || *digits > 3)
		return (0);
	*commas += 1;
	*digits = 0;
	return (1);
}
