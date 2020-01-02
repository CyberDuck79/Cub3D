/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:51 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/01 11:24:19 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set(unsigned char *ptr, unsigned char c, size_t len)
{
	while (len--)
	{
		ptr[0] = c;
		ptr[1] = c;
		ptr[2] = c;
		ptr[3] = c;
		ptr[4] = c;
		ptr[5] = c;
		ptr[6] = c;
		ptr[7] = c;
		ptr[8] = c;
		ptr[9] = c;
		ptr[10] = c;
		ptr[11] = c;
		ptr[12] = c;
		ptr[13] = c;
		ptr[14] = c;
		ptr[15] = c;
		ptr += 16;
	}
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cccc;
	unsigned char	*ptr;

	cccc = (unsigned char)c;
	ptr = (unsigned char*)b;
	while (len % 16)
	{
		*ptr++ = cccc;
		len--;
	}
	len /= 16;
	ft_set(ptr, cccc, len);
	return (b);
}
