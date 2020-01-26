/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:35:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/26 14:45:06 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

int			apply_fog(double dist, int texel)
{
	int r = texel & 0xFF;
	int g = (texel >> 8) & 0xFF;
	int b = (texel >> 16) & 0xFF;

	r -= (int)dist + 16;
	if (r < 0x10)
		r = 0x10;
	g -= (int)dist + 16;
	if (g < 0x10)
		g = 0x10;
	b -= (int)dist + 16;
	if (b < 0x10)
		b = 0x10;
	return (r | g << 8 | b << 16);
}

static void	wall_calc(t_cam *cam, t_text *text)
{
	if (cam->ray.side)
		cam->wall.x = cam->ray.pos_x + cam->wall.dist * cam->ray.dir_x;
	else
		cam->wall.x = cam->ray.pos_y + cam->wall.dist * cam->ray.dir_y;
	cam->wall.x -= floor(cam->wall.x);
	text->x = (int)(cam->wall.x * 64.0);
	if (cam->ray.side && cam->ray.dir_y < 0)
		text->x = 64 - text->x - 1;
	if (!cam->ray.side && cam->ray.dir_x > 0)
		text->x = 64 - text->x - 1;
}

static void	floor_calc(t_cam *cam)
{
	if (cam->ray.side == 0 && cam->ray.dir_x > 0) {
		cam->floor.start_x = cam->ray.map_x;
		cam->floor.start_y = cam->ray.map_y + cam->wall.x;
	} else if (cam->ray.side == 0 && cam->ray.dir_x < 0) {
		cam->floor.start_x = cam->ray.map_x + 1.0;
		cam->floor.start_y = cam->ray.map_y + cam->wall.x;
	} else if (cam->ray.side == 1 && cam->ray.dir_y > 0) {
		cam->floor.start_x = cam->ray.map_x + cam->wall.x;
		cam->floor.start_y = cam->ray.map_y;
	} else {
		cam->floor.start_x = cam->ray.map_x + cam->wall.x;
		cam->floor.start_y = cam->ray.map_y + 1.0;
	}
}

static void	ft_put_wall(t_cub3d *cub, int x, int y, t_text *text)
{
	int	texel;
	int	height;

	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	height = cub->cam.wall.height;
	text->y = y * 2 - cub->wy + height;
	text->y = ((text->y) * 32) / height;
	texel = text->data[text->x + text->y * 64];
	texel = apply_fog(cub->cam.wall.dist * 16, texel);
	ft_memcpy(cub->img.addr + (x + y * cub->wx), &texel, sizeof(int));
}

static void	ft_put_floor(t_cub3d *cub, int x, int y, t_text *text)
{
	int		texel;
	double	weight;

	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	cub->cam.floor.dist = cub->wy / (2.0 * y - cub->wy);
	weight = cub->cam.floor.dist / cub->cam.wall.dist;
	cub->cam.floor.x = weight * cub->cam.floor.start_x + (1.0 - weight) * cub->cam.pos_x;
	cub->cam.floor.y = weight * cub->cam.floor.start_y + (1.0 - weight) * cub->cam.pos_y;
	text->x = (int)(cub->cam.floor.x * 64) % 64;
	text->y = (int)(cub->cam.floor.y * 64) % 64;
	texel = text->data[text->x + text->y * 64];
	texel = apply_fog(cub->cam.floor.dist * 36, texel);
	ft_memcpy(cub->img.addr + (x + (y - 1) * cub->wx), &texel, sizeof(int));
	ft_memcpy(cub->img.addr + (x + (cub->wy - y - 1) * cub->wx), &texel, sizeof(int));
}

void		draw(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	wall_calc(&cub->cam, &cub->text[3]);
	floor_calc(&cub->cam);
	y = wall->start;
	while (y <= wall->end)
		ft_put_wall(cub, x, y++, &cub->text[3]);
	while (y < cub->wy)
		ft_put_floor(cub, x, y++, &cub->text[2]);
}