/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:03:43 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 13:24:55 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

static void	move_up(t_cub3d *cub, t_cam *cam)
{

	if (!cub->map.map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_x * cam->ms)])
		cam->pos_x += cam->dir_x * cam->ms;
	if (!cub->map.map[(int)(cam->pos_y + cam->dir_y * cam->ms)][(int)cam->pos_x])
		cam->pos_y += cam->dir_y * cam->ms;
}

static void	move_down(t_cub3d *cub, t_cam *cam)
{
	if (!cub->map.map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_x * cam->ms)])
		cam->pos_x -= cam->dir_x * cam->ms;
	if (!cub->map.map[(int)(cam->pos_y - cam->dir_y * cam->ms)][(int)cam->pos_x])
		cam->pos_y -= cam->dir_y * cam->ms;
}

static void	rotate_right(t_cam *cam)
{
	double	dir_x;
	double	plane_x;

	dir_x = cam->dir_x;
	cam->dir_x = dir_x * cos(-cam->rs) - cam->dir_y * sin(-cam->rs);
	cam->dir_y = dir_x * sin(-cam->rs) + cam->dir_y * cos(-cam->rs);
	plane_x = cam->plane_x;
	cam->plane_x = plane_x * cos(-cam->rs) - cam->plane_y * sin(-cam->rs);
	cam->plane_y = plane_x * sin(-cam->rs) + cam->plane_y * cos(-cam->rs);
}

static void	rotate_left(t_cam *cam)
{
	double	dir_x;
	double	plane_x;

	dir_x = cam->dir_x;
	cam->dir_x = dir_x * cos(cam->rs) - cam->dir_y * sin(cam->rs);
	cam->dir_y = dir_x * sin(cam->rs) + cam->dir_y * cos(cam->rs);
	plane_x = cam->plane_x;
	cam->plane_x = plane_x * cos(cam->rs) - cam->plane_y * sin(cam->rs);
	cam->plane_y = plane_x * sin(cam->rs) + cam->plane_y * cos(cam->rs);
}

int			move(t_cub3d *cub)
{
	if (cub->move.up)
		move_up(cub, &cub->cam);
	if (cub->move.down)
		move_down(cub, &cub->cam);
	if (cub->move.right)
		rotate_right(&cub->cam);
	if (cub->move.left)
		rotate_left(&cub->cam);
	frame(cub, &cub->cam);
	return (0);
}