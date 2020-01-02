/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlst_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 10:03:25 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:16:24 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrlst_fd(t_list *lst, char separator, int fd)
{
	if (!lst)
		return ;
	while (lst->next)
	{
		ft_putnbr_fd(*((int*)lst->content), fd);
		ft_putchar_fd(separator, fd);
		lst = lst->next;
	}
	ft_putnbr_fd(*((int*)lst->content), fd);
}
