/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:22:23 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 14:13:06 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(unsigned char *dst, unsigned char *src, size_t len)
{
	while (len--)
	{
		dst[0] = src[0];
		dst[1] = src[1];
		dst[2] = src[2];
		dst[3] = src[3];
		dst[4] = src[4];
		dst[5] = src[5];
		dst[6] = src[6];
		dst[7] = src[7];
		dst[8] = src[8];
		dst[9] = src[9];
		dst[10] = src[10];
		dst[11] = src[11];
		dst[12] = src[12];
		dst[13] = src[13];
		dst[14] = src[14];
		dst[15] = src[15];
		dst += 16;
		src += 16;
	}
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (len % 16)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		len--;
	}
	len /= 16;
	ft_cpy(pdst, psrc, len);
	return (dst);
}
