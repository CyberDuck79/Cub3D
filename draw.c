/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:35:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 17:08:13 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

static void	text_x_calc(t_cam *cam, t_text *text)
{
	if (cam->ray.side)
		cam->wall.x = cam->pos_x + cam->wall.dist * cam->ray.dir_x;
	else
		cam->wall.x = cam->pos_y + cam->wall.dist * cam->ray.dir_y;
	text->x = (int)(cam->wall.x * (double)(64));
	if (cam->ray.side && cam->ray.dir_y < 0)
		text->x = 64 - text->x - 1;
	if (!cam->ray.side && cam->ray.dir_x > 0)
		text->x = 64 - text->x - 1;
	text->x = abs(text->x);
}

static void	text_y_calc(t_cub3d *cub, t_text *text, int y)
{
	int	height;

	height = cub->cam.wall.height;
	text->y = y * 256 - cub->wy * 128 + height * 128;
	text->y = (((text->y) * 64) / height) / 256;
	text->y = abs(text->y);
}

static void	ft_put_color(t_cub3d *cub, int x, int y, int color)
{
	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	ft_memcpy(cub->img.addr + (x + y * cub->wx), &color, sizeof(int));
}

static void	ft_put_texture(t_cub3d *cub, int x, int y, t_text *text)
{
	int	texel;

	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	text_y_calc(cub, text, y);
	texel = text->data[text->x % 64 + text->y % 64 * 64];
	ft_memcpy(cub->img.addr + (x + y * cub->wx), &texel, sizeof(int));
}

void		draw(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	y = 0;
	text_x_calc(&cub->cam, &cub->text[cub->cam.wall.dir]);
	while (y < wall->start)
		ft_put_color(cub, x, y++, cub->color[1]);
	while (y <= wall->end)
		ft_put_texture(cub, x, y++, &cub->text[wall->dir]);
	while (y < cub->wx)
		ft_put_color(cub, x, y++, cub->color[0]);
}