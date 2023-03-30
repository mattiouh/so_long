/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:12:12 by gpecci            #+#    #+#             */
/*   Updated: 2023/01/20 12:28:52 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = NULL;
	tmp = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		tmp[i] = (unsigned char) c;
		i++;
	}
	return ((void *) b);
}
