/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:03:44 by sgury             #+#    #+#             */
/*   Updated: 2019/05/24 15:51:38 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_size_error(t_data_tab *data)
{
	if (data->flags[h])
		ft_putstr_fd("error: size 'h' should be use for type short", 2);
	else if (data->flags[hh])
		ft_putstr_fd("error: size 'hh' should be use for type char", 2);
	else if (data->flags[l])
		ft_putstr_fd("error: size 'l' should be use for type long", 2);
	else if (data->flags[hh] == 0)
	{
		ft_putstr_fd("error: use [h | hh | l | ll]", 2);
		ft_putstr_fd("if parameter is not type int", 2);
	}
	exit(1);
}
