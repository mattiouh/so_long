/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:14:31 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/30 12:34:04 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	control_ber(char *argv)

{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i] != '.')
		i++;
	if (argv[i + 1] != 'b' || argv[i + 2] != 'e'
		|| argv[i + 3] != 'r' || argv[i + 4] != '\0')
		return (0);
	return (1);
}

int	count_row(char *s)

{
	int	l;
	int	counter;

	counter = 0;
	l = 0;
	while (s[l])
	{
		if (s[l] == '\n')
			counter++;
		l++;
	}
	return (counter + 1);
}

int	control(t_vars *vars)
{
	if (!vars->map)
		return (0);
	else if (check_wall(vars) == 0)
		return (0);
	else if (check_frst_lst(vars) == 0)
		return (0);
	else if (check_strt(vars) == 0)
		return (0);
	else if (check_vars(vars) == 0)
		return (0);
	else
		return (1);
}
