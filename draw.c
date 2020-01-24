/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:35:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/24 18:46:51 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

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
	ft_memcpy(cub->img.addr + (x + y * cub->wx), &texel, sizeof(int));
}

static void	ft_put_floor(t_cub3d *cub, int x, int y, t_text *text)
{
	double current_dist = cub->wy / (2.0 * y - cub->wy);
	double weight = current_dist / cub->cam.wall.dist;
	double current_x = weight * cub->cam.floor.start_x + (1.0 - weight) * cub->cam.pos_x;
	double current_y = weight * cub->cam.floor.start_y + (1.0 - weight) * cub->cam.pos_y;
	int floor_x = (int)(current_x * 64) % 64;
	int floor_y = (int)(current_y * 64) % 64;
	int texel = text->data[floor_x + floor_y * 64];
	
	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	ft_memcpy(cub->img.addr + (x + (y - 1) * cub->wx), &texel, sizeof(int));
	ft_memcpy(cub->img.addr + (x + (cub->wy - y - 1) * cub->wx), &texel, sizeof(int));
}

void		draw(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	wall_calc(&cub->cam, &cub->text[cub->cam.wall.dir]);
	floor_calc(&cub->cam);
	y = wall->start;
	while (y <= wall->end)
		ft_put_wall(cub, x, y++, &cub->text[wall->dir]);
	while (y < cub->wy)
		ft_put_floor(cub, x, y++, &cub->text[2]);
}