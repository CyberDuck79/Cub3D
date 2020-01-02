/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:28:02 by fhenrion          #+#    #+#             */
/*   Updated: 2019/10/26 10:12:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(strjoin = (char*)ft_calloc(len1 + len2 + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcpy(strjoin + len1, s2, len2 + 1);
	return (strjoin);
}
