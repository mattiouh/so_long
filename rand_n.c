/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:09 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/27 14:19:32 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rand_n(t_vars *vars)
{
	if (vars->rand_c == 1 && vars->mewtwo > 0)
	{
		vars->rand_x = vars->player_x;
		vars->rand_y = vars->player_y;
	}
	if (vars->rand_c == 5 && vars->mewtwo > 0)
	{
		vars->map[vars->n_x][vars->n_y] = '0';
		if (vars->map[vars->rand_y][vars->rand_x] == 'P')
		{
			vars->deathflag = 1;
			tele_rand_death(vars);
		}
		if (vars->map[vars->rand_y][vars->rand_x] != 'P')
			vars->map[vars->rand_y][vars->rand_x] = 'N';
		vars->rand_c = 0;
		draw_map(vars);
	}
	vars->rand_c++;
}

void	tele_rand_death(t_vars *vars)
{
	if (vars->map[vars->rand_y - 1][vars->rand_x] == '0')
		vars->map[vars->rand_y - 1][vars->rand_x] = 'N';
	else if (vars->map[vars->rand_y + 1][vars->rand_x] == '0')
		vars->map[vars->rand_y + 1][vars->rand_x] = 'N';
	else if (vars->map[vars->rand_y][vars->rand_x - 1] == '0')
		vars->map[vars->rand_y][vars->rand_x - 1] = 'N';
	else if (vars->map[vars->rand_y][vars->rand_x + 1] == '0')
		vars->map[vars->rand_y][vars->rand_x + 1] = 'N';
}
