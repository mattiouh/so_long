/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:52:13 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 18:46:00 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_event(int keycode, t_vars *vars)
{
	if (vars->deathflag == 0)
	{
		if ((keycode == 13 || keycode == 126) && vars->ctc_flag == 0)
			move_up(vars);
		if ((keycode == 1 || keycode == 125) && vars->ctc_flag == 0)
			move_down(vars);
		if ((keycode == 0 || keycode == 123) && vars->ctc_flag == 0)
			move_left(vars);
		if ((keycode == 2 || keycode == 124) && vars->ctc_flag == 0)
			move_right(vars);
		if (keycode == 49 && vars->trowable > 0)
		{
			image_trw(vars);
			trow_masterball(vars);
		}
	}
}

void	move_up(t_vars *vars)
{
	up_anim(vars);
	vars->sideflag = 1;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'E')
		if (vars->mewtwo == 0 && vars->collectable == 0)
			vars->victory_flag = 1;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'N')
		vars->deathflag = 1;
	if (vars->map[vars->player_y - 1][vars->player_x] == 'C')
	{
		collectables(vars);
		vars->map[vars->player_y - 1][vars->player_x] = '0';
		draw_map(vars);
	}
	else if (vars->map[vars->player_y - 1][vars->player_x] == '0')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->map[vars->player_y - 1][vars->player_x] = 'P';
		draw_map(vars);
		vars->movement++;
		terminal_display(vars);
		info_display(vars);
		rand_n(vars);
	}
}

void	move_down(t_vars *vars)
{
	down_anim(vars);
	vars->sideflag = 2;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E')
		if (vars->mewtwo == 0 && vars->collectable == 0)
			vars->victory_flag = 1;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'N')
		vars->deathflag = 1;
	if (vars->map[vars->player_y + 1][vars->player_x] == 'C')
	{
		vars->map[vars->player_y + 1][vars->player_x] = '0';
		collectables(vars);
		draw_map(vars);
	}
	else if (vars->map[vars->player_y + 1][vars->player_x] == '0')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->map[vars->player_y + 1][vars->player_x] = 'P';
		draw_map(vars);
		vars->movement++;
		terminal_display(vars);
		info_display(vars);
		rand_n(vars);
	}
}

void	move_left(t_vars *vars)
{
	left_anim(vars);
	vars->sideflag = 3;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'E')
		if (vars->mewtwo == 0 && vars->collectable == 0)
			vars->victory_flag = 1;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'N')
		vars->deathflag = 1;
	if (vars->map[vars->player_y][vars->player_x - 1] == 'C')
	{
		vars->map[vars->player_y][vars->player_x - 1] = '0';
		collectables(vars);
		draw_map(vars);
	}
	else if (vars->map[vars->player_y][vars->player_x - 1] == '0')
	{
		vars->map[vars->player_y][vars->player_x - 1] = 'P';
		vars->map[vars->player_y][vars->player_x] = '0';
		draw_map(vars);
		vars->movement++;
		terminal_display(vars);
		info_display(vars);
		rand_n(vars);
	}
}

void	move_right(t_vars *vars)
{
	right_anim(vars);
	vars->sideflag = 4;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E')
		if (vars->mewtwo == 0 && vars->collectable == 0)
			vars->victory_flag = 1;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'N')
		vars->deathflag = 1;
	if (vars->map[vars->player_y][vars->player_x + 1] == 'C')
	{
		vars->map[vars->player_y][vars->player_x + 1] = '0';
		collectables(vars);
		draw_map(vars);
	}
	else if (vars->map[vars->player_y][vars->player_x + 1] == '0')
	{
		vars->map[vars->player_y][vars->player_x] = '0';
		vars->map[vars->player_y][vars->player_x + 1] = 'P';
		draw_map(vars);
		vars->movement++;
		terminal_display(vars);
		info_display(vars);
		rand_n(vars);
	}
}
