/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:19:40 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 16:57:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgrfx.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->size_x || y < 0 || y >= img->size_y)
		return ;
	*(img->ptr + ((x + y * img->size_x))) = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, img->size_x * img->size_y * img->bpp);
}

t_img	*del_image(t_env *env, t_img *img)
{
	if (img)
	{
		if (img->ip)
			mlx_destroy_image(env->mp, img->ip);
		free(img);
	}
	return (NULL);
}

t_img	*new_image(t_env *env, int size_x, int size_y)
{
	t_img		*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->ip = mlx_new_image(env->mp, size_x, size_y)))
		return (del_image(env, img));
	img->ptr = (int *)mlx_get_data_addr(img->ip, &img->bpp, &img->sizeln,
			&img->endian);
	img->bpp /= 8;
	img->size_x = size_x;
	img->size_y = size_y;
	return (img);
}
