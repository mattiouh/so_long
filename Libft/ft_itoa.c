/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:41:29 by mpalombi          #+#    #+#             */
/*   Updated: 2023/01/26 17:42:19 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(long nbr)
{
	size_t	l;

	l = 0;
	if (nbr <= 0)
	{
		l++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*result;
	size_t	i;

	nb = n;
	i = ft_size(nb);
	result = (char *)malloc(i + 1);
	if (!result)
		return (NULL);
	result[i--] = 0;
	if (nb < 0)
	{
		result[0] = 45;
		nb = -nb;
	}
	while (nb > 9)
	{
		result[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	if (nb >= 0 && nb <= 9)
		result[i] = 48 + nb;
	return (result);
}
