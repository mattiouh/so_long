/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:03:47 by mpalombi          #+#    #+#             */
/*   Updated: 2023/01/26 12:02:53 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (*(tmp_s1 + i) != *(tmp_s2 + i))
		{
			return (*(tmp_s1 + i) - *(tmp_s2 + i));
		}
		i++;
	}
	return (0);
}
