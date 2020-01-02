/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:36:08 by fhenrion          #+#    #+#             */
/*   Updated: 2019/10/27 16:55:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char*)dst)[index] = ((unsigned char*)src)[index];
		if (((unsigned char*)src)[index] == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
