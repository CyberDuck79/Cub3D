/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:58:40 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 14:26:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab_fd(char **tab, char separator, int fd)
{
	if (!tab || !*tab)
		return ;
	while (tab[1])
	{
		ft_putstr_fd(*tab, fd);
		ft_putchar_fd(separator, fd);
		tab++;
	}
	ft_putstr_fd(*tab, fd);
}
