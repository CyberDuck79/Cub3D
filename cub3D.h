/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:17:32 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/07 15:32:46 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

# define BUFFER_SIZE 4096
# define WINX 1024
# define WINY 768

typedef enum	e_error
{
	OK,
	ARGUMENT,
	FILE,
	EXTENSION,
	RESOLUTION,
	TEXTURES,
	COLORS,
	MAP
}				t_error;

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

// voir pour découper la structure en sous-structures
typedef struct	s_cub3D
{
	int			wx;
	int			wy;
	void		*mlx;
	void		*win;
	char		*map_name;
	t_tex		tex[4];
	/*
	t_tex		tex[9];
	void		*img;
	void		*img_ptr;
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			help;
	int			x_text;
	int			y_text;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	double		walldist;
	double		x_olddir;
	double		x_oldplane;
	double		ms;
	double		rs;
	double		x_wall;
	double		x_floor;
	double		y_floor;
	double		x_curfloortext;
	double		y_curfloortext;
	double		curdist;
	double		weight;
	*/
}				t_cub3D;

t_error			map_parser(t_cub3D *t, char *filename);
/*
void			draw_sky(t_cub3D *t);
void			draw_floor(t_cub3D *t);
void			draw_wall(int x, int start, int end, t_cub3D *t);
void			put_pxl_to_img(t_cub3D *t, int x, int y, int color);

int				key_press2(int keycode, t_cub3D *t);
int				key_press(int keycode, t_cub3D *t);
int				key_release(int keycode, t_cub3D *t);
void			move_side(t_cub3D *t);
int				move(t_cub3D *t);

void			help_text(t_cub3D *t);

void			load_textures(t_cub3D *t);
void			load_textures2(t_cub3D *t, int a, int b);

int				ft_close(void);
void			mlx_win_init(t_cub3D *t);
void			wolf3d_init(t_cub3D *t);

t_error			map_parser(t_cub3D *t, char *filename);
int				parser2(t_cub3D *t, char **av);

void			ray_casting(t_cub3D *t);
void			ray_casting_init(t_cub3D *t, int x);
void			floor_and_ceiling(t_cub3D *t, int x);
void			dda(t_cub3D *t);
void			dda_init(t_cub3D *t);
*/
#endif
