/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:22:15 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/31 11:53:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"
#include "utils.h"

static int	on_screen(int wx, double z_buf, double trans_y, int x)
{
	return (trans_y > 0 && x > 0 && x < wx && trans_y < z_buf);
}

static void	calc_sprite_pos(t_cub3d *cub, t_sprite *sprt, t_draw *pos)
{
	pos->y = -sprt->height / 2 + cub->wy / 2;
	if (pos->y < 0)
		pos->y = 0;
	pos->y_end = sprt->height / 2 + cub->wy / 2;
	if (pos->y_end >= cub->wy)
		pos->y_end = cub->wy - 1;
	pos->x = -sprt->height / 2 + sprt->side;
	if (pos->x < 0)
		pos->x = 0;
	pos->x_end = sprt->height / 2 + sprt->side;
	if (pos->x_end >= cub->wx)
		pos->x_end = cub->wx - 1;
}

static void	draw_sprite(t_cub3d *cub, t_ray *ray, t_sprite *sprt, t_text *text)
{
	t_draw	pos;
	int		y;
	int		texel;

	calc_sprite_pos(cub, sprt, &pos);
	while (pos.x < pos.x_end)
	{
		if (on_screen(cub->wx, ray->z_buf[pos.x], sprt->trans_y, pos.x))
		{
			text->x = (int)(256 * (pos.x - (-sprt->height / 2 + sprt->side)) \
			* 64 / sprt->height) / 256;
			y = pos.y;
			while (y < pos.y_end)
			{
				sprt->d = y * 256 - cub->wy * 128 + sprt->height * 128;
				text->y = ((sprt->d * 64) / sprt->height) / 256;
				texel = text->data[text->y * 64 + text->x];
				if (BONUS)
					texel = apply_fog((cub->wy / sprt->height) * 8, texel);
				draw_transparency(cub, texel, pos.x + (y - 1) * cub->wx);
				y++;
			}
		}
		pos.x++;
	}
}

void		draw_sprites(t_cub3d *cub, t_cam *cam, t_sprite *arr, int size)
{
	int		i;
	double	inv;

	
	i = 0;
	inv = 1.0 / (cam->plane_x * cam->dir_y - cam->plane_y * cam->dir_x);
	while (i < size)
	{
		arr[i].x = arr[i].map_x - cam->pos_x;
		arr[i].y = arr[i].map_y - cam->pos_y;
		arr[i].trans_x = inv * (cam->dir_y * arr[i].x - cam->dir_x * arr[i].y);
		arr[i].trans_y = inv * (-cam->plane_y * arr[i].x + cam->plane_x \
		* arr[i].y);
		arr[i].side = (int)((cub->wx / 2) * \
		(1 + arr[i].trans_x / arr[i].trans_y));
		arr[i].height = abs((int)(cub->wy / arr[i].trans_y));
		draw_sprite(cub, &cam->ray, &arr[i], &cub->text[4]);
		i++;
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
		x = map->sprites[i].map_x;
		y = map->sprites[i].map_y;
		map->sprites[i].dist = pow(cam->pos_x - x, 2) * pow(cam->pos_y - y, 2);
		i++;
	}
	sort_sprites(map->sprites, map->sprites_nb);
}
