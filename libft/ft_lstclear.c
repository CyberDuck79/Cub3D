/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:39:12 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 13:48:07 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *lst_next;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		lst_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_next;
	}
	*lst = NULL;
}
