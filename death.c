/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:17:09 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 18:40:30 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	death(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	if (vars->death_stage == 1)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/death/death1.xpm", &x, &y);
	if (vars->death_stage == 2)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/death/death2.xpm", &x, &y);
	if (vars->death_stage == 3)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/death/death3.xpm", &x, &y);
	if (vars->death_stage == 4)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->death_scrn, 0, vars->height - 102);
	if (vars->death_stage == 10)
	{
		free_map(vars);
		exit(0);
	}
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free (vars->map);
}

void	victory_anim(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->victory_stage == 1)
		win_stg_1(vars);
	if (vars->victory_stage == 2)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/win/win2.xpm", &x, &y);
	if (vars->victory_stage == 3)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/win/win3.xpm", &x, &y);
	if (vars->victory_stage == 4)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/win/win4.xpm", &x, &y);
	if (vars->victory_stage == 5)
		vars->player = mlx_xpm_file_to_image(vars->mlx,
				"/Users/mpalombi/42cursus/so_long/win/win5.xpm", &x, &y);
	if (vars->victory_stage == 6)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->victory_scrn, 0, vars->height - 102);
	if (vars->victory_stage == 12)
	{
		exit(0);
		free_map(vars);
	}
}

void	victory(t_vars *vars)
{
	if (vars->victory_loop < 3000)
		vars->victory_loop++;
	if (vars->victory_loop == 3000)
	{
		vars->victory_stage++;
		victory_anim(vars);
		draw_map(vars);
		vars->victory_loop = 0;
	}
}

void	win_stg_1(t_vars *vars)
{
	int	x;
	int	y;

	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/win/win1.xpm", &x, &y);
}
