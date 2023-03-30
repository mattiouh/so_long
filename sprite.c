/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:13:28 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 19:03:12 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite(t_vars *vars)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	vars->victory_scrn = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/win/win6.xpm", &x, &y);
	vars->death_scrn = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/death/death4.xpm", &x, &y);
	i += back_walls(vars);
	i += player_exit_sprite(vars);
	i += master_mewtwo_sprite(vars);
	if (i != 3)
	{
		free_map(vars);
		exit (1);
	}
}

int	back_walls(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->background = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/background.xpm", &x, &y);
	if (!vars->background)
		return (0);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/wall.xpm", &x, &y);
	if (!vars->wall)
		return (0);
	return (1);
}

int	player_exit_sprite(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/idle/idle1.xpm", &x, &y);
	if (!vars->player)
		return (0);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/exit.xpm", &x, &y);
	if (!vars->exit)
		return (0);
	return (1);
}

int	master_mewtwo_sprite(t_vars *vars)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	vars->masterball = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/masterball.xpm", &x, &y);
	if (!vars->masterball)
		return (0);
	vars->enemy = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/mewtwo1.xpm", &x, &y);
	if (!vars->mewtwo)
		return (0);
	return (1);
}
