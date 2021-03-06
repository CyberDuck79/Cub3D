/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:55:02 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 12:10:24 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "utils.h"

int	key_press(int keycode, t_cub3d *cub)
{
	if (keycode == 13 || keycode == 126)
		cub->move.up = 1;
	else if (keycode == 1 || keycode == 125)
		cub->move.down = 1;
	else if (keycode == 2)
		cub->move.right = 1;
	else if (keycode == 0)
		cub->move.left = 1;
	else if (keycode == 12 || keycode == 123)
		cub->move.r_left = 1;
	else if (keycode == 14 || keycode == 124)
		cub->move.r_right = 1;
	else if (keycode == 257 || keycode == 258)
		cub->cam.ms = 0.1;
	else if (keycode == 53)
		close_game(cub);
	return (0);
}

int	key_release(int keycode, t_cub3d *cub)
{
	if (keycode == 13 || keycode == 126)
		cub->move.up = 0;
	else if (keycode == 1 || keycode == 125)
		cub->move.down = 0;
	else if (keycode == 2)
		cub->move.right = 0;
	else if (keycode == 0)
		cub->move.left = 0;
	else if (keycode == 12 || keycode == 123)
		cub->move.r_left = 0;
	else if (keycode == 14 || keycode == 124)
		cub->move.r_right = 0;
	else if (keycode == 257 || keycode == 258)
		cub->cam.ms = 0.05;
	return (0);
}
