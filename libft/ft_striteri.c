/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielji <danielji@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:54:12 by danielji          #+#    #+#             */
/*   Updated: 2025/12/24 18:53:40 by danielji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Apply the function `f` to each character of the string passed as argument,
passing its index as the first argument. Each character is passed by address
to `f` so it can be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
