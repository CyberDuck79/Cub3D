/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:34:10 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 16:36:05 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_error	write_header(t_cub3d *cub, int fd, int size)
{
	unsigned char	header_buf[54];

	ft_bzero(header_buf, sizeof(header_buf));
	header_buf[0] = (unsigned char)('B');
	header_buf[1] = (unsigned char)('M');
	ft_memcpy(header_buf + 2, &size, sizeof(int));
	header_buf[10] = (unsigned char)(54);
	header_buf[14] = (unsigned char)(40);
	ft_memcpy(header_buf + 18, &cub->wx, sizeof(int));
	ft_memcpy(header_buf + 22, &cub->wy, sizeof(int));
	header_buf[27] = (unsigned char)(1);
	header_buf[28] = (unsigned char)(24);
	return ((write(fd, header_buf, 54) == 54) ? OK : OPEN_FILE);
}

static t_error	write_data(t_cub3d *cub, int fd, ssize_t pad_size)
{
	int						x;
	int						y;
	int						color;
	int						rgb;
	const unsigned char		padding[3] = {0};

	y = cub->wy - 1;
	while (y > -1)
	{
		x = 0;
		while (x < cub->wx)
		{
			color = cub->img.addr[x + y * cub->wx];
			rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
			if (write(fd, &rgb, 3) != 3)
				return (OPEN_FILE);
			if (pad_size && write(fd, padding, pad_size) != pad_size)
				return (OPEN_FILE);
			x++;
		}
		y--;
	}
	return (OK);
}

t_error			save_bmp(t_cub3d *cub)
{
	int		fd;
	int		size;
	ssize_t	pad_size;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644)) < 0)
		return (OPEN_FILE);
	pad_size = (4 - (cub->wx * 3) % 4) % 4;
	size = 54 + (3 * (cub->wx + pad_size) * cub->wy);
	if (write_header(cub, fd, size))
		return (OPEN_FILE);
	if (write_data(cub, fd, pad_size))
		return (OPEN_FILE);
	close(fd);
	return (OK);
}
