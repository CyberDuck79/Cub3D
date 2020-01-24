/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:17:32 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/24 14:25:40 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ray_casting.h"

# define BUFFER_SIZE 4096
# define WINX 1024
# define WINY 768

typedef enum	e_error
{
	OK,
	ARGUMENT,
	OPEN_FILE,
	EXTENSION,
	SYNTAX,
	RESOLUTION,
	TEXTURES,
	COLORS,
	MAP
}				t_error;

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
}				t_map;

typedef struct	s_move
{
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
}				t_move;

typedef struct	s_cub3d
{
	int			wx;
	int			wy;
	void		*mlx;
	void		*win;
	char		params;
	int			color[2];
	t_text		text[4];
	t_img		img;
	t_map		map;
	t_cam		cam;
	t_move		move;
	clock_t		old_time;
	clock_t		time;
}				t_cub3d;

t_error			file_parser(t_cub3d *cub, const char *filename);
void			frame(t_cub3d *cub, t_cam *cam);
void			draw(t_cub3d *cub, t_wall *wall, int x);
int				key_press(int keycode, t_cub3d *cub);
int				key_release(int keycode, t_cub3d *cub);
int				move(t_cub3d *cub);
int				**escape_free_map(int **map, int index_stop);
int				ft_close(t_cub3d *cub);
void			print_fps(t_cub3d *cub);

#endif
