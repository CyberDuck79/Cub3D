/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:45:20 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:20:54 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrchr(const char *s, char c)
{
	size_t	index;
	size_t	len;
	char	*sub;

	if (!s || !s[0])
		return (NULL);
	if ((index = ft_strchri(s, c)) == -1)
		return (ft_strdup(s));
	len = index + 1;
	if (!(sub = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(sub, s, len);
	return (sub);
}
