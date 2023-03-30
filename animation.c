/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:13:00 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 18:16:38 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_vars *vars)
{
	if (vars->ctc_flag == 1)
		ctc_flag(vars);
	if (vars->deathflag == 0 && vars->victory_flag == 0)
		animation_flag(vars);
	if (vars->deathflag == 1)
		death_animation(vars);
	if (vars->victory_flag == 1)
		victory(vars);
	return (0);
}

void	change_animation(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->enemy);
	if (vars->stage == 1)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/idle/idle1.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo1.xpm", &x, &y);
	}
	else if (vars->stage == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/idle/idle2.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo2.xpm", &x, &y);
		vars->stage = 0;
	}
}

void	ctc_flag(t_vars *vars)
{
	if (vars->ctc_loop < 3000)
			vars->ctc_loop++;
	if (vars->ctc_loop == 3000)
	{
		vars->ctc_loop = 0;
		vars->ctc_flag = 0;
	}
}

void	animation_flag(t_vars *vars)
{
	if (vars->a_loop < 4000)
		vars->a_loop++;
	if (vars->a_loop == 4000)
	{
		vars->stage++;
		vars->a_loop = 0;
		if (vars->sideflag == 1)
			idle_anim_up(vars);
		if (vars->sideflag == 2)
			change_animation(vars);
		if (vars->sideflag == 3)
			idle_anim_left(vars);
		if (vars->sideflag == 4)
			idle_anim_right(vars);
		draw_map(vars);
	}
}

void	death_animation(t_vars *vars)
{
	if (vars->death_loop < 4000)
		vars->death_loop++;
	if (vars->death_loop == 4000)
	{
		vars->death_stage++;
		death(vars);
		draw_map(vars);
		vars->death_loop = 0;
	}
}
