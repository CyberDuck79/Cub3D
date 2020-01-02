/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:51:38 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/12 10:04:19 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (dst == src)
		return (dst);
	if (psrc <= pdst)
		while (len-- > 0)
			pdst[len] = psrc[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
