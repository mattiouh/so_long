/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:22:56 by mpalombi          #+#    #+#             */
/*   Updated: 2023/01/28 12:19:51 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*str;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return ((void *)str);
}
