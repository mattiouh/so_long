/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:04:50 by mpalombi          #+#    #+#             */
/*   Updated: 2023/01/26 19:10:43 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	index;
	int		sign;
	int		result;

	result = 0;
	sign = 1;
	index = 0;
	while ((str[index] == 32) || (str[index] >= 9 && str[index] <= 13))
	{
		index++;
	}
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10;
		result = result + str[index] - '0';
		index++;
	}
	return (result * sign);
}
