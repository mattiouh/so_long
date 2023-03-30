/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:47:17 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 17:37:36 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_anim(t_vars *vars)
{
	int	x;
	int	y;

	vars->stg_2++;
	if (vars->stg_2 == 1)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/up/up1.xpm", &x, &y);
	}
	if (vars->stg_2 == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/up/up2.xpm", &x, &y);
		vars->stg_2 = 0;
	}
}

void	down_anim(t_vars *vars)
{
	int	x;
	int	y;

	vars->stg_2++;
	if (vars->stg_2 == 1)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/down/down1.xpm", &x, &y);
	}
	if (vars->stg_2 == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/down/down2.xpm", &x, &y);
		vars->stg_2 = 0;
	}
}

void	left_anim(t_vars *vars)
{
	int	x;
	int	y;

	vars->stg_2++;
	if (vars->stg_2 == 1)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"//Users/mpalombi/42cursus/so_long/left/left1.xpm", &x, &y);
	}
	if (vars->stg_2 == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/left/left2.xpm", &x, &y);
		vars->stg_2 = 0;
	}
}

void	right_anim(t_vars *vars)
{
	int	x;
	int	y;

	vars->stg_2++;
	if (vars->stg_2 == 1)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"//Users/mpalombi/42cursus/so_long/right/right1.xpm", &x, &y);
	}
	if (vars->stg_2 == 2)
	{
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/right/right2.xpm", &x, &y);
		vars->stg_2 = 0;
	}
}
