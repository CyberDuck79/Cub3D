/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:49:21 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:25:57 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstchrsplit(const char *s, char c)
{
	size_t	index;
	char	**split;
	t_list	*lst;

	index = 1;
	split = ft_split(s, c);
	lst = ft_lstnew(*split);
	while (split[index])
	{
		ft_lstadd_back(&lst, ft_lstnew(split[index]));
		index++;
	}
	free(split);
	return (lst);
}
