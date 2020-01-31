/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:52:35 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/31 11:36:03 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

# include "cub3d.h"

typedef struct	s_sprite
{
	double		map_x;
	double		map_y;
	double		dist;
	double		x;
	double		y;
	double		trans_x;
	double		trans_y;
	int			side;
	int			height;
	int			d;
}				t_sprite;

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
	double		*z_buf;
}				t_ray;

typedef struct	s_wall
{
	double		dist;
	int			height;
	int			start;
	int			end;
	int			dir;
	double		x;
}				t_wall;

typedef struct	s_floor
{
	double		start_x;
	double		start_y;
	double		dist;
	double		x;
	double		y;
}				t_floor;

typedef struct	s_cam
{
	double		x;
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
	t_floor		floor;
}				t_cam;

typedef struct	s_move
{
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
	int			r_left:1;
	int			r_right:1;
}				t_move;

typedef struct	s_text
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
}				t_text;

typedef struct	s_img
{
	void		*ptr;
	int			*addr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_map
{
	char		*map_name;
	int			**map;
	int			x;
	int			y;
	int			start_x;
	int			start_y;
	char		start_dir;
	int			sprites_nb;
	t_sprite	*sprites;
}				t_map;

typedef struct	s_cub3d
{
	int			wx;
	int			wy;
	void		*mlx;
	void		*win;
	char		params;
	int			color[2];
	t_text		text[5];
	t_img		img;
	t_img		sprite_img;
	t_map		map;
	t_cam		cam;
	t_move		move;
	clock_t		old_time;
	clock_t		time;
}				t_cub3d;

#endif
