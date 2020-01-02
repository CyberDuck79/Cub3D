/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:15:02 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:28:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*list;

	list = (t_list*)ft_calloc(1, sizeof(t_list));
	if (list)
	{
		if (!content)
			list->content = NULL;
		else
			list->content = (void*)content;
		list->next = NULL;
	}
	return (list);
}
