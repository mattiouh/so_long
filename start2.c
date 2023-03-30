/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:21:40 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/30 13:40:40 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	start2(t_vars *vars, char *argv)
{
	vars->fd = open(argv, O_RDONLY);
	if (vars->fd < 0)
	{
		free_map(vars);
		exit (1);
	}
	read(vars->fd, vars->s1, 1000000);
	vars->map = ft_split(vars->s1, '\n');
	free(vars->s1);
	vars->row = count_row(vars->s1);
	vars->height = vars->row * 64 ;
	vars->width = ft_strlen(vars->map[0]) * 64;
	vars->win = mlx_new_window(vars->mlx, vars->width,
			vars->height + 64, "Mpalombi");
	return (*vars);
}
