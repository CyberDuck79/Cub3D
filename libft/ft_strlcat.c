/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:20:26 by flavien           #+#    #+#             */
/*   Updated: 2019/11/04 13:50:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	src_i;
	size_t	dst_i;
	size_t	return_size;

	src_i = 0;
	dst_i = ft_strlen(dst);
	if (len <= dst_i)
		return (len + ft_strlen(src));
	return_size = dst_i + ft_strlen(src);
	while (dst_i < len - 1 && src[src_i])
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	return (return_size);
}
