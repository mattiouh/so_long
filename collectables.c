/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:21:35 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 18:16:49 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectables(t_vars *vars)
{
	vars->trowable += 1;
	vars->collectable -= 1;
}

void	trow_masterball(t_vars *vars)
{
	if ((vars->sideflag == 1)
		&& (vars->map[vars->player_y - 1][vars->player_x] == '0'
		|| vars->map[vars->player_y - 1][vars->player_x] == 'N'))
		trw_up(vars);
	if ((vars->sideflag == 2)
		&& (vars->map[vars->player_y + 1][vars->player_x] == '0'
		|| vars->map[vars->player_y + 1][vars->player_x] == 'N'))
		trw_down(vars);
	if ((vars->sideflag == 3)
		&& (vars->map[vars->player_y][vars->player_x - 1] == '0'
		|| vars->map[vars->player_y][vars->player_x - 1] == 'N'))
		trw_left(vars);
	if ((vars->sideflag == 4)
		&& (vars->map[vars->player_y][vars->player_x + 1] == '0'
		|| vars->map[vars->player_y][vars->player_x + 1] == 'N'))
		trw_right(vars);
}

void	image_trw(t_vars *vars)
{
	int	x;
	int	y;

	x = 256;
	y = 256;
	mlx_clear_window(vars->mlx, vars->win);
	vars->catch = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/chatchanim2.xpm", &x, &y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->catch, vars->width / 2 - 100, vars->height / 2 - 100);
	vars->ctc_flag = 1;
	info_display(vars);
}

void	info_display(t_vars *vars)
{
	char	*s1;
	int		x;
	int		y;

	s1 = ft_itoa(vars->movement);
	vars->black = mlx_xpm_file_to_image(vars->mlx,
			"/Users/mpalombi/42cursus/so_long/texture/black.xpm", &x, &y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->black,
		150, vars->height + 22);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->black,
		250, vars->height + 22);
	mlx_string_put(vars->mlx, vars->win, 150, vars->height + 22,
		0x00FFFFFF, "Moves: ");
	mlx_string_put(vars->mlx, vars->win, 250, vars->height + 22,
		0x00FFFFFF, s1);
	free(s1);
}
