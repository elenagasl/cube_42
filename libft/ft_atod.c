/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:42:43 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:46:45 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	trim_space(int *i, char *str)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
}

static int	is_negative(int *i, char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[(*i)++] == '-')
			return (-1);
	}
	return (1);
}

/* Convert the string `str` to a double floating number */
double	ft_atod(char *str)
{
	int		i;
	int		sign;
	int		decimal;
	double	result;

	i = 0;
	decimal = 0;
	result = 0.0;
	if (!str || !str[i])
		return (0);
	trim_space(&i, str);
	sign = is_negative(&i, str);
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		if (str[i] == '.' && !decimal)
			decimal = i;
		if (str[i] != '.')
			result = (result) * 10 + str[i] - '0';
		i++;
	}
	decimal = i - decimal;
	while (--decimal > 0)
		result = result / 10.0;
	return ((double)(sign * result));
}
