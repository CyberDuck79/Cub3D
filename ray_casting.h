/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:05:59 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 10:50:40 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

typedef struct	s_dda
{
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
}				t_dda;

typedef struct	s_ray
{
	int			x;
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			side;
	t_dda		dda;
}				t_ray;

typedef struct	s_wall
{
	double		dist;
	int			height;
	int			start;
	int			end;
	int			color;
}				t_wall;

typedef struct	s_cam
{
	double		cam_x;
	double		cam_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ms;
	double		rs;
	t_ray		ray;
	t_wall		wall;
}				t_cam;

#endif