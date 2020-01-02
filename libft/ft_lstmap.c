/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:53:23 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 13:49:11 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *elem), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*next;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = ft_lstnew(f(lst->content))) || !(new_lst->content))
	{
		ft_lstdelone(new_lst, del);
		return (NULL);
	}
	tmp = new_lst;
	while ((lst = lst->next))
	{
		if (!(next = ft_lstnew(f(lst->content))) || !(next->content))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp->next = next;
		tmp = next;
	}
	return (new_lst);
}
