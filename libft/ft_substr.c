/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:03:53 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 12:02:43 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		index;
	size_t	end;
	char	*substr;

	if (!s)
		return (NULL);
	index = 0;
	end = start + len;
	if (!(substr = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (start > ft_strlen(s))
		return (substr);
	while ((start < end) && s[start])
		substr[index++] = s[start++];
	return (substr);
}
