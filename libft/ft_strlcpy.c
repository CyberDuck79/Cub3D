/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:03:52 by flavien           #+#    #+#             */
/*   Updated: 2019/11/08 12:42:06 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (!len)
		return (src_len);
	else if (src_len < len - 1)
		ft_memcpy(dst, src, src_len + 1);
	else
	{
		ft_memcpy(dst, src, len - 1);
		dst[len - 1] = '\0';
	}
	return (src_len);
}
