/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:31:28 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/24 15:40:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray_casting.h"

static void	dda_init(t_ray *ray, t_dda *dda)
{
	dda->delta_x = fabs(1 / ray->dir_x);
	dda->delta_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_x = (ray->pos_x - ray->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (ray->map_x + 1.0 - ray->pos_x) * dda->delta_x;
	}
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_y = (ray->pos_y - ray->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (ray->map_y + 1.0 - ray->pos_y) * dda->delta_y;
	}
}

static void	dda(int	**map, t_ray *ray)
{
	dda_init(ray, &ray->dda);
	while (1)
	{
		if (ray->dda.side_x < ray->dda.side_y)
		{
			ray->dda.side_x += ray->dda.delta_x;
			ray->map_x += ray->dda.step_x;
			ray->side = 0;
		}
		else
		{
			ray->dda.side_y += ray->dda.delta_y;
			ray->map_y += ray->dda.step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] > 0)
			return ;
	}
}

static void	ray_casting(t_cub3d *cub, t_cam *cam, t_ray *ray)
{
	cam->x = 2 * ray->x / (double)cub->wx - 1;
	ray->pos_x = cam->pos_x;
	ray->pos_y = cam->pos_y;
	ray->dir_x = cam->dir_x + cam->plane_x * cam->x;
	ray->dir_y = cam->dir_y + cam->plane_y * cam->x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	dda(cub->map.map, ray);
	if (ray->side)
		cam->wall.dist = (ray->map_y - ray->pos_y + \
		(1 - ray->dda.step_y) / 2) / ray->dir_y;
	else
		cam->wall.dist = (ray->map_x - ray->pos_x + \
		(1 - ray->dda.step_x) / 2) / ray->dir_x;
}

void		frame(t_cub3d *cub, t_cam *cam)
{
	while (cam->ray.x < cub->wx)
	{
		ray_casting(cub, cam, &cam->ray);
		cam->wall.height = (int)(cub->wy / cam->wall.dist);
		cam->wall.start = -cam->wall.height / 2 + cub->wy / 2;
		if (cam->wall.start < 0)
			cam->wall.start = 0;
		cam->wall.end = cam->wall.height / 2 + cub->wy / 2;
		if (cam->wall.start >= cub->wy)
			cam->wall.end = cub->wy - 1;
		if (cam->ray.side)
			cam->wall.dir = cam->ray.dir_y < 0 ? 0 : 1;
		else
			cam->wall.dir = cam->ray.dir_x < 0 ? 2 : 3;
		draw(cub, &cam->wall, cam->ray.x);
		cam->ray.x++;
	}
	cam->ray.x = 0;
	print_fps(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
	ft_bzero(cub->img.addr, cub->wx * cub->wy * cub->img.bpp);
}