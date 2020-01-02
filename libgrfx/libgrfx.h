/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgrfx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:15:19 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 17:00:44 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRFX_H
# define LIBGRFX_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef enum	e_error
{
	NO_ERROR,
	MLX_ERROR,
	WINDOW_ERROR,
	IMG_ERROR,
}				t_error;

typedef struct	s_img
{
	void		*ip;
	int			*ptr;
	int			bpp;
	int			sizeln;
	int			endian;
	int			size_x;
	int			size_y;
}				t_img;

typedef struct	s_env
{
	void	*mp;
	void	*wp;
	t_img	*img;
	int		wx;
	int		wy;
}				t_env;

typedef struct	s_vect2
{
	int	x;
	int	y;
}				t_vect2;

typedef struct	s_vect3
{
	int	x;
	int	y;
	int	z;
}				t_vect3;

typedef struct	s_line
{
	t_vect2	*pt1;
	t_vect2	*pt2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e;
}				t_line;

t_error			clear_env(t_env *env);
void			del_env(t_env *env);
t_error			new_env(t_env *env, int size_x, int size_y, char *title);
void			put_pixel(t_img *img, int x, int y, int color);
void			clear_image(t_img *img);
t_img			*del_image(t_env *env, t_img *img);
t_img			*new_image(t_env *env, int size_x, int size_y);
t_vect2			*vect2_init(int x, int y);
t_vect3			*vect3_init(int x, int y, int z);
t_line			*line_init(t_vect2 *pt1, t_vect2 *pt2);
void			draw_line(t_env *env, t_line *line, int color);
void			change_line_coord(t_line *line, int x1, int y1, int x2, int y2);
void			free_line(t_line *line);

#endif
