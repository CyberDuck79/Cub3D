/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 16:56:08 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 16:09:40 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgrfx.h"

t_line		*line_init(t_vect2 *pt1, t_vect2 *pt2)
{
	t_line	*line;

	if (!(line = malloc(sizeof(t_line))))
		return (NULL);
	line->pt1 = pt1;
	line->pt2 = pt2;
	line->dx = abs(pt2->x - pt1->x);
	line->dy = abs(pt2->y - pt1->y);
	line->sx = pt1->x < pt2->x ? 1 : -1;
	line->sy = pt1->y < pt2->y ? 1 : -1;
	line->e = (line->dx > line->dy ? line->dx : -line->dy) / 2;
	return (line);
}

static void	line_calc(t_line *line)
{
	line->dx = abs(line->pt2->x - line->pt1->x);
	line->dy = abs(line->pt2->y - line->pt1->y);
	line->sx = line->pt1->x < line->pt2->x ? 1 : -1;
	line->sy = line->pt1->y < line->pt2->y ? 1 : -1;
	line->e = (line->dx > line->dy ? line->dx : -line->dy) / 2;
}

void		draw_line(t_env *env, t_line *line, int color)
{
	int	x;
	int	y;
	int	e;

	x = line->pt1->x;
	y = line->pt1->y;
	while (1)
	{
		put_pixel(env->img, x, y, color);
		if (x == line->pt2->x && y == line->pt2->y)
			return ;
		e = line->e;
		if (e > -line->dx)
		{
			line->e -= line->dy;
			x += line->sx;
		}
		if (e < line->dy)
		{
			line->e += line->dx;
			y += line->sy;
		}
	}
}

void		change_line_coord(t_line *line, int x1, int y1, int x2, int y2)
{
	line->pt1->x = x1;
	line->pt1->y = y1;
	line->pt2->x = x2;
	line->pt2->y = y2;
	line_calc(line);
}

void		free_line(t_line *line)
{
	free(line->pt1);
	free(line->pt2);
	free(line);
}