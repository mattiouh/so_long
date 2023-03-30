/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:02:47 by mpalombi          #+#    #+#             */
/*   Updated: 2023/01/26 18:41:47 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*tmps1 && *tmps2 && *tmps1 == *tmps2 && n > 0)
	{
		tmps1++;
		tmps2++;
		n--;
	}
	if (n > 0)
		return (*tmps1 - *tmps2);
	return (0);
}
