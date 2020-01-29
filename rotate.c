/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:09:12 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 11:11:35 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "rotate.h"

void	rotate_right(t_cam *cam)
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

void	rotate_left(t_cam *cam)
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
