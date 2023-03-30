/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:13:16 by mpalombi          #+#    #+#             */
/*   Updated: 2023/03/28 18:53:57 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>
# include "Libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*s1;
	int		fd;
	char	*pd;
	int		row;
	char	**map;
	int		map_x;
	int		map_y;
	void	*wall;
	void	*background;
	void	*masterball;
	int		collectable;
	void	*exit;
	void	*death;
	void	*enemy;
	void	*player;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
	int		playerc;
	int		exitc;
	int		mewtwo;
	int		deathflag;
	int		trowable;
	int		sideflag;
	int		trw_x;
	int		trw_y;
	int		movement;
	int		rand_x;
	int		rand_y;
	int		n_y;
	int		n_x;
	int		rand_c;
	int		stage;
	int		a_loop;
	void	*catch;
	int		ctc_loop;
	int		ctc_flag;
	int		death_loop;
	int		death_stage;
	void	*death_scrn;
	int		victory_flag;
	int		victory_loop;
	int		victory_stage;
	void	*victory_scrn;
	int		stg_2;
	void	*black;

}				t_vars;

int		check_wall(t_vars *vars);
int		check_frst_lst(t_vars *vars);
int		check_strt(t_vars *vars);
int		check_vars(t_vars *vars);
int		control_ber(char *argv);
int		count_row(char *s);
int		control(t_vars *vars);
int		draw_map(t_vars *vars);
void	draw_1_0(t_vars *vars, int x, int y);
void	draw_p_n(t_vars *vars, int x, int y);
void	draw_c_e(t_vars *vars, int x, int y);
int		main(int argc, char **argv);
void	sprite(t_vars *vars);
int		back_walls(t_vars *vars);
int		player_exit_sprite(t_vars *vars);
int		master_mewtwo_sprite(t_vars *vars);
t_vars	start(t_vars *vars, char *argv);
t_vars	start2(t_vars *vars, char *argv);
int		key_esc(int keycode, t_vars *vars);
int		key_x(t_vars *vars);
void	move_event(int keycode, t_vars *vars);
void	move_up(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	death(t_vars *vars);
void	collectables(t_vars *vars);
void	ft_exit(t_vars *vars);
void	victory(t_vars *vars);
void	trow_masterball(t_vars *vars);
void	trw_up(t_vars *vars);
void	trw_down(t_vars *vars);
void	trw_left(t_vars *vars);
void	trw_right(t_vars *vars);
void	terminal_display(t_vars *vars);
void	ft_putstr(char *s1);
void	rand_n(t_vars *vars);
int		animation(t_vars *vars);
void	change_animation(t_vars *vars);
void	image_trw(t_vars *vars);
void	ctc_flag(t_vars *vars);
void	animation_flag(t_vars *vars);
void	death_animation(t_vars *vars);
void	tele_rand_death(t_vars *vars);
void	victory_anim(t_vars *vars);
void	up_anim(t_vars *vars);
void	down_anim(t_vars *vars);
void	left_anim(t_vars *vars);
void	right_anim(t_vars *vars);
void	idle_anim_up(t_vars *vars);
void	idle_anim_left(t_vars *vars);
void	idle_anim_right(t_vars *vars);
void	info_display(t_vars *vars);
void	win_stg_1(t_vars *vars);
void	free_map(t_vars *vars);

#endif
