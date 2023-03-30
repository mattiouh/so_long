/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trw_master.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:45:13 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/27 10:14:34 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trw_up(t_vars *vars)
{
	vars->trw_x = vars->player_x;
	vars->trw_y = vars->player_y;
	while (vars->map[vars->trw_y - 1][vars->trw_x] != '1'
		&& vars->map[vars->trw_y - 1][vars->trw_x] != 'E'
		&& vars->map[vars->trw_y - 1][vars->trw_x] != 'C')
	{
		vars->trw_y--;
		if (vars->map[vars->trw_y][vars->trw_x] == 'N')
		{
			vars->mewtwo--;
			break ;
		}
	}
	vars->map[vars->trw_y][vars->trw_x] = 'C';
	draw_map(vars);
	vars->trowable--;
	vars->collectable++;
}

void	trw_down(t_vars *vars)
{
	vars->trw_x = vars->player_x;
	vars->trw_y = vars->player_y;
	while (vars->map[vars->trw_y + 1][vars->trw_x] != '1'
		&& vars->map[vars->trw_y + 1][vars->trw_x] != 'E'
		&& vars->map[vars->trw_y + 1][vars->trw_x] != 'C')
	{
		vars->trw_y++;
		if (vars->map[vars->trw_y][vars->trw_x] == 'N')
		{
			vars->mewtwo--;
			break ;
		}
	}
	vars->map[vars->trw_y][vars->trw_x] = 'C';
	draw_map(vars);
	vars->trowable--;
	vars->collectable++;
}

void	trw_left(t_vars *vars)
{
	vars->trw_x = vars->player_x;
	vars->trw_y = vars->player_y;
	while (vars->map[vars->trw_y][vars->trw_x - 1] != '1'
		&& vars->map[vars->trw_y][vars->trw_x - 1] != 'E'
		&& vars->map[vars->trw_y][vars->trw_x - 1] != 'C')
	{
		vars->trw_x--;
		if (vars->map[vars->trw_y][vars->trw_x] == 'N')
		{
			vars->mewtwo--;
			break ;
		}
	}
	vars->map[vars->trw_y][vars->trw_x] = 'C';
	draw_map(vars);
	vars->trowable--;
	vars->collectable++;
}

void	trw_right(t_vars *vars)
{
	vars->trw_x = vars->player_x;
	vars->trw_y = vars->player_y;
	while (vars->map[vars->trw_y][vars->trw_x + 1] != '1'
		&& vars->map[vars->trw_y][vars->trw_x + 1] != 'E'
		&& vars->map[vars->trw_y][vars->trw_x + 1] != 'C')
	{
		vars->trw_x++;
		if (vars->map[vars->trw_y][vars->trw_x] == 'N')
		{
			vars->mewtwo--;
			break ;
		}
	}
	vars->map[vars->trw_y][vars->trw_x] = 'C';
	draw_map(vars);
	vars->trowable--;
	vars->collectable++;
}
