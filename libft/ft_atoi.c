/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:12:39 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:47:06 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert the initial portion of the string pointed to by `nptr` to `int`.
Same as `strtol(nptr, NULL, 10);` except that `atoi()` does not detect errors.
The string may begin with an arbitrary amount of white space (as determined by
`isspace(3)`) followed by a single optional `+` or `-` sign.
The remainder of the string is converted to a long value in the obvious manner,
stopping at the first character which is not a valid digit in the given base.
Return the converted value or `0` on error. */
int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	return ((int)(nbr * sign));
}
