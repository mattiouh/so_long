/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:48:48 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 20:15:28 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	if (!vars->map)
		return (0);
	if (vars->ctc_flag == 0 && vars->death_stage < 4 && vars->victory_stage < 6)
	{
		while (y < vars->row)
		{
			x = 0;
			while (x < vars->width / 64)
			{
				if (vars->map[y][x] == '1' || vars->map[y][x] == '0')
					draw_1_0(vars, x, y);
				else if (vars->map[y][x] == 'P' || vars->map[y][x] == 'N')
					draw_p_n(vars, x, y);
				else if (vars->map[y][x] == 'C' || vars->map[y][x] == 'E')
					draw_c_e(vars, x, y);
				x++;
			}
			y++;
		}
	}
	return (0);
}

void	draw_1_0(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, x * 64, y * 64);
	}
	if (vars->map[y][x] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
	}
}

void	draw_p_n(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player, x * 64 + 8, y * 64);
		vars->player_x = x;
		vars->player_y = y;
	}
	if (vars->map[y][x] == 'N')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->enemy, x * 64, y * 64);
		vars->n_x = y;
		vars->n_y = x;
	}
}

void	draw_c_e(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->masterball, x * 64, y * 64);
	}
	if (vars->map[y][x] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, x * 64, y * 64);
	}
}
