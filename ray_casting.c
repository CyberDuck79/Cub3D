/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 11:31:28 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/28 17:13:38 by fhenrion         ###   ########.fr       */
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
		if (map[ray->map_y][ray->map_x] == 1)
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

void		draw_sprite(t_cub3d *cub, t_map *map, t_cam *cam)
{
	int		i;

	i = 0;
	while (i < map->sprites_nb)
	{
		double sprite_x = map->sprites[i].x - cam->pos_x;
		double sprite_y = map->sprites[i].y - cam->pos_y;
		double inv = 1.0 / (cam->plane_x * cam->dir_y - cam->plane_y * cam->dir_x);
		double transformX = inv * (cam->dir_y * sprite_x - cam->dir_x * sprite_y);
		double transformY = inv * (-cam->plane_y * sprite_x + cam->plane_x * sprite_y);
		int draw_x = (int)((cub->wx / 2) * (1 + transformX / transformY));
		int	draw_h = abs((int)(cub->wy / transformY));
		int draw_start_y = -draw_h / 2 + cub->wy / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		int draw_end_y = draw_h / 2 + cub->wy / 2;
		if (draw_end_y >= cub->wy)
			draw_end_y = cub->wy - 1;
		int draw_w = abs((int)(cub->wy / transformY));
		int draw_start_x = -draw_w / 2 + draw_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		int draw_end_x = draw_w / 2 + draw_x;
		if (draw_end_x >= cub->wx)
			draw_end_x = cub->wx - 1;
		int x = draw_start_x;
		while (x < draw_end_x)
		{
			if (transformY > 0 && x > 0 && x < cub->wx && transformY < cam->ray.z_buf[x])
			{
				int text_x = (int)(256 * (x - (-draw_w / 2 + draw_x)) * 64 / draw_w) / 256;
				int y = draw_start_y;
				while (y < draw_end_y)
				{
					int d = y * 256 - cub->wy * 128 + draw_h * 128;
					int text_y = ((d * 64) / draw_h) / 256;
					int texel = cub->text[4].data[text_y * 64 + text_x];
					ft_memcpy(cub->img.addr + (x + (y - 1) * cub->wx), &texel, sizeof(int));
					y++;
				}
			}
			x++;
		}
		i++;
	}
}

void		sort_sprites(t_sprite *sprites, int sprites_nb)
{
	int i;
	int sorted;
	t_sprite tmp;

	sorted = 1;
	while (sorted)
	{
		i = 0;
		sorted = 0;
		while (i < sprites_nb - 1)
		{
			if (sprites[i].dist < sprites[i + 1].dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
				sorted++;
			}
			i++;
		}
	}
	
}

void		sprite_casting(t_map *map, t_cam *cam)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	while (i < map->sprites_nb)
	{
		x = map->sprites[i].x;
		y = map->sprites[i].y;
		map->sprites[i].dist = pow(cam->pos_x - x, 2) * pow(cam->pos_y - y, 2);
		i++;
	}
	sort_sprites(map->sprites, map->sprites_nb); // du plus grand au plus petit
}

void		frame(t_cub3d *cub, t_cam *cam)
{
	while (cam->ray.x < cub->wx)
	{
		ray_casting(cub, cam, &cam->ray);
		cam->ray.z_buf[cam->ray.x] = cam->wall.dist;
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
	sprite_casting(&cub->map, cam);
	draw_sprite(cub, &cub->map, cam);
	cam->ray.x = 0;
	//if (BONUS)
		print_fps(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
}