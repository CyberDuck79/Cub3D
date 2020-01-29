/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:03:43 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 11:28:39 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	move_up(int **map, t_cam *cam)
{
	if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_x * cam->ms * 3)])
		cam->pos_x += cam->dir_x * cam->ms;
	if (!map[(int)(cam->pos_y + cam->dir_y * cam->ms * 3)][(int)cam->pos_x])
		cam->pos_y += cam->dir_y * cam->ms;
}

void	move_down(int **map, t_cam *cam)
{
	if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_x * cam->ms * 3)])
		cam->pos_x -= cam->dir_x * (cam->ms / 2);
	if (!map[(int)(cam->pos_y - cam->dir_y * cam->ms * 3)][(int)cam->pos_x])
		cam->pos_y -= cam->dir_y * (cam->ms / 2);
}

void	move_right(int **map, t_cam *cam)
{
	if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_y * cam->ms * 3)])
		cam->pos_x -= cam->dir_y * (cam->ms / 2);
	if (!map[(int)(cam->pos_y + cam->dir_x * cam->ms * 3)][(int)cam->pos_x])
		cam->pos_y += cam->dir_x * (cam->ms / 2);
}

void	move_left(int **map, t_cam *cam)
{
	if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_y * cam->ms * 3)])
		cam->pos_x += cam->dir_y * (cam->ms / 2);
	if (!map[(int)(cam->pos_y - cam->dir_x * cam->ms * 3)][(int)cam->pos_x])
		cam->pos_y -= cam->dir_x * (cam->ms / 2);
}
