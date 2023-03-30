/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:51:50 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/30 13:37:53 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	start(t_vars *vars, char *argv)
{
	vars->mlx = mlx_init();
	vars->player_x = 0;
	vars->player_y = 0;
	vars->deathflag = 0;
	vars->trowable = 0;
	vars->rand_c = 0;
	vars->n_x = 0;
	vars->n_y = 0;
	vars->stage = 0;
	vars->a_loop = 0;
	vars->movement = 0;
	vars->ctc_flag = 0;
	vars->ctc_loop = 0;
	vars->death_loop = 0;
	vars->death_stage = 0;
	vars->victory_flag = 0;
	vars->victory_stage = 0;
	vars->sideflag = 2;
	vars->playerc = 0;
	vars->mewtwo = 0;
	vars->exitc = 0;
	vars->stg_2 = 0;
	vars->s1 = malloc(sizeof(char) * 1000000);
	start2(vars, argv);
	return (*vars);
}
