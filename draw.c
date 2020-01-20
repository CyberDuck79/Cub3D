/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:35:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/20 15:29:23 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//// change for textures
void	ft_put_pixel(t_cub3d *cub, int x, int y, int color)
{
	if (x < 0 || x >= cub->wx || y < 0 || y >= cub->wy)
		return ;
	ft_memcpy(cub->img.addr + (x + y * cub->wx), &color, sizeof(int));
}

/*
void	draw_sky(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	y = 0;
	while (y < wall->start)
		ft_put_pixel(cub, x, y++, wall->color);
}

void	draw_wall(t_cub3d *cub, t_wall *wall, int x)
{
	//// do some calc for textures
	while (wall->start <= wall->end)
		ft_put_pixel(cub, x, wall->start++, wall->color);
}

void	draw_floor(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	y = wall->end + 1;
	while (y < cub->wx)
		ft_put_pixel(cub, x, y++, wall->color);
}
*/
// naive draw function for test -> change for texture
void	draw(t_cub3d *cub, t_wall *wall, int x)
{
	int y;

	y = 0;
	while (y < wall->start)
		ft_put_pixel(cub, x, y++, cub->color[1]);
	while (y <= wall->end)
		ft_put_pixel(cub, x, y++, wall->color);
	while (y < cub->wx)
		ft_put_pixel(cub, x, y++, cub->color[0]);
}