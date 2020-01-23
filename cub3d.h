/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:17:32 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 10:11:24 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
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

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

typedef struct	s_img
{
	void		*ptr;
	void		*addr;
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

// voir pour découper la structure en sous-structures
typedef struct	s_cub3d
{
	int			wx;
	int			wy;
	void		*mlx;
	void		*win;
	char		params;
	int			color[2];
	t_tex		tex[4];
	t_img		img;
	t_map		map;
	t_cam		cam;
}				t_cub3d;

int				**escape_free_map(int **map, int index_stop);
t_error			file_parser(t_cub3d *cub, const char *filename);
void			frame(t_cub3d *cub, t_cam *cam);
void			draw(t_cub3d *cub, t_wall *wall, int x);

#endif
