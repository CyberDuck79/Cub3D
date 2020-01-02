/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:30:12 by flavien           #+#    #+#             */
/*   Updated: 2019/11/04 11:07:46 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_tochar(int n)
{
	n %= 10;
	if (n < 0)
		n = -n;
	return ((char)n + 48);
}

static size_t	ft_size(int n)
{
	size_t	size;

	size = n < 0 ? 2 : 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_size(n);
	if (!(str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	if (!n)
		*str = '0';
	else if (n < 0)
		*str = '-';
	while (n)
	{
		size--;
		str[size] = ft_tochar(n);
		n /= 10;
	}
	return (str);
}
