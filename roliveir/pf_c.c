/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:35:31 by sgury             #+#    #+#             */
/*   Updated: 2019/06/04 00:47:26 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_flags(int c, t_data_tab *data, t_buff *buff)
{
	int	spaces;

	spaces = data->flags[width];
	if (data->flags[just_left])
	{
		ft_buffer(c, buff);
		while (--spaces > 0)
			ft_buffer(' ', buff);
	}
	else
	{
		while (--spaces > 0)
			ft_buffer(' ', buff);
		ft_buffer(c, buff);
	}
}

int			pf_c(va_list ap, t_data_tab *data, t_buff *buff)
{
	int	c;
	int	i;

	i = 0;
	c = va_arg(ap, int);
	if (data->flags[width] > 1)
		c_flags(c, data, buff);
	else
		ft_buffer(c, buff);
	return (0);
}
