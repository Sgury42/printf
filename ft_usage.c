/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:30:02 by sgury             #+#    #+#             */
/*   Updated: 2019/05/23 17:35:37 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_usage(char conv)
{
	ft_putstr_fd("usage:\t%[flags][width][.precision][size]convertion\n", 2);
	if (conv == 'z')
		ft_putstr_fd("\tconvertion: cspdiouxX\n", 2);
	else if (conv == 'c')
		ft_putstr_fd("\t%[-][width]c\n", 2);
	else if (conv == 's')
		ft_putstr_fd("\t%[-][width]s\n", 2);
	else if (conv == 'd')
	{
		ft_putstr_fd("\t%[- | + | 0 ][width][.precision][h | l | hh | ll]d\n", 2);
		ft_putstr_fd("\tincompatible [- & 0]\n\tno double size\n", 2);
	}
	exit (1);
}
