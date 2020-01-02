/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:18:09 by fhenrion          #+#    #+#             */
/*   Updated: 2019/10/26 15:35:17 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (((unsigned char*)s)[index] == (unsigned char)c)
			return ((void*)s + index);
		index++;
	}
	return (NULL);
}
