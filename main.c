/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:46:07 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/30 13:41:20 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		start(&vars, argv[1]);
		if (control(&vars) == 0 || control_ber(argv[1]) == 0)
		{
			write(1, "error\n", 6);
			free_map(&vars);
			exit(0);
		}
		sprite(&vars);
		draw_map(&vars);
		mlx_hook(vars.win, 3, 1L << 1, key_esc, &vars);
		mlx_hook(vars.win, 17, 0, key_x, &vars);
		mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_loop(vars.mlx);
	}
}

int	key_esc(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free_map(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
		move_event(keycode, vars);
	return (0);
}

int	key_x(t_vars *vars)
{
	free_map(vars);
	exit(0);
	return (0);
}

void	terminal_display(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->movement);
	ft_putstr("Moves: ");
	ft_putstr(str);
	ft_putstr("\n");
	free(str);
}

void	ft_putstr(char *s1)
{
	if (!s1)
		return ;
	write(1, s1, ft_strlen(s1));
}
