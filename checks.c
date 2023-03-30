/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:55:01 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/30 13:37:44 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_vars *vars)
{
	int	y;

	y = 0;
	while (vars->map[0][y] && vars->map[vars->row - 1][y])
	{
		if ((vars->map[0][y] != '1') || (vars->map[vars->row - 1][y] != '1'))
			return (0);
		y++;
	}
	return (1);
}

int	check_frst_lst(t_vars *vars)
{
	int	i;
	int	c;

	i = 0;
	c = ft_strlen(vars->map[0]) - 1;
	while (i < vars->row)
	{
		if ((vars->map[i][0] != '1') || (vars->map[i][c] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_strt(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < vars->row)
	{
		if (ft_strlen(vars->map[x]) != ft_strlen(vars->map[0]))
			return (0);
		x++;
	}
	if (ft_strlen(vars->map[0]) == (size_t)(x))
		return (0);
	return (1);
}

int	check_vars(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
				vars->playerc += 1;
			if (vars->map[i][j] == 'C')
				vars->collectable += 1;
			if (vars->map[i][j] == 'N')
				vars->mewtwo += 1;
			if (vars->map[i][j] == 'E')
				vars->exitc += 1;
			j++;
		}
		i++;
	}
	if (vars->playerc != 1 || vars->collectable == 0
		|| vars->mewtwo != 1 || vars->exitc != 1)
		return (0);
	return (1);
}
