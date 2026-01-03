/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:10:51 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:49:16 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return `1` if character is printable (including tabs and spaces) */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
