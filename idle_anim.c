/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:18:13 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 17:48:36 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	idle_anim_up(t_vars *vars)
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
				"/Users/mpalombi/42cursus/so_long/up/idleup1.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo1.xpm", &x, &y);
	}
	else if (vars->stage == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"//Users/mpalombi/42cursus/so_long/up/idleup2.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo2.xpm", &x, &y);
		vars->stage = 0;
	}
}

void	idle_anim_left(t_vars *vars)
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
				"/Users/mpalombi/42cursus/so_long/left/idleleft1.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo1.xpm", &x, &y);
	}
	else if (vars->stage == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/left/idleleft2.xpm", &x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo2.xpm", &x, &y);
		vars->stage = 0;
	}
}

void	idle_anim_right(t_vars *vars)
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
				"/Users/mpalombi/42cursus/so_long/right/idleright1.xpm",
				&x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo1.xpm", &x, &y);
	}
	else if (vars->stage == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/right/idleright2.xpm",
				&x, &y);
		vars->enemy = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/texture/mewtwo2.xpm", &x, &y);
		vars->stage = 0;
	}
}
