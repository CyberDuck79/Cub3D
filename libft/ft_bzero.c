/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:07:36 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:15:57 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set(unsigned char *ptr, size_t len)
{
	while (len--)
	{
		ptr[0] = 0;
		ptr[1] = 0;
		ptr[2] = 0;
		ptr[3] = 0;
		ptr[4] = 0;
		ptr[5] = 0;
		ptr[6] = 0;
		ptr[7] = 0;
		ptr[8] = 0;
		ptr[9] = 0;
		ptr[10] = 0;
		ptr[11] = 0;
		ptr[12] = 0;
		ptr[13] = 0;
		ptr[14] = 0;
		ptr[15] = 0;
		ptr += 16;
	}
}

void		ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	while (len % 16)
	{
		*ptr++ = 0;
		len--;
	}
	len /= 16;
	ft_set(ptr, len);
}
