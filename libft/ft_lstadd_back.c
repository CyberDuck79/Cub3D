/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:32:26 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:25:37 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	lst = *alst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}
