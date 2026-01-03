/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:41:59 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:49:20 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return `1` if character is a space, horizontal tab (`\t`), newline (`\n`),
vertical tab (`\v`), form-feed (`\f`), or carriage return (`\r`)*/
int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
