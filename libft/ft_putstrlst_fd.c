/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlst_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:58:48 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:19:35 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrlst_fd(t_list *lst, char separator, int fd)
{
	if (!lst)
		return ;
	while (lst->next)
	{
		ft_putstr_fd((char*)lst->content, fd);
		ft_putchar_fd(separator, fd);
		lst = lst->next;
	}
	ft_putstr_fd((char*)lst->content, fd);
}
