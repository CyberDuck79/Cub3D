/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:13:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 17:36:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int pos_x = 50;
int pos_y = 50;

static void	print_square(t_env *env, int x, int y)
{
	t_line *line;

	line = line_init(vect2_init(x, y), vect2_init(x, y + 10));
	draw_line(env, line, 0x00FFFFFF);
	change_line_coord(line, x, y + 10, x + 10, y + 10);
	draw_line(env, line, 0x00FFFFFF);
	change_line_coord(line, x + 10, y + 10, x + 10, y);
	draw_line(env, line, 0x00FFFFFF);
	change_line_coord(line, x + 10, y, x, y);
	draw_line(env, line, 0x00FFFFFF);
	mlx_put_image_to_window(env->mp, env->wp, env->img->ip, 0, 0);
	free_line(line);
}

static int	events(int key, t_env *env)
{
	if (key == S_KEY)
		pos_y += 2;
	else if (key == W_KEY)
		pos_y -= 2;
	else if (key == D_KEY)
		pos_x += 2;
	else if (key == A_KEY)
		pos_x -= 2;
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
	{
		clear_env(env);
		print_square(env, pos_x, pos_y);
	}
	if (key == ESCAPE_KEY)
		del_env(env);
	return (0);
}

int			main(void)
{
	t_env	env;

	new_env(&env, WIN_X, WIN_Y, "Cub3D");
	print_square(&env, pos_x, pos_y);
	mlx_key_hook(env.wp, events, &env);
	mlx_loop(env.mp);
	return (0);
}
