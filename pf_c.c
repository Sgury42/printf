/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:35:31 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 16:55:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_flags(int c, t_data_tab *data, t_buff *buff)
{
	int	spaces;

	spaces = data->flags[10];
	if (data->flags[0])
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

int		pf_c(va_list ap, t_data_tab *data, t_buff *buff)
{
	int		c;
	int		just_left;
	int		spaces;
	int		i;

	i = 0;
	just_left = 0;
	spaces = 0;
	while (++i < 10)
		if (data->flags[i] || data->flags[11])
			ft_usage();
	c = va_arg(ap, int);
	if (data->flags[10])
		c_flags(c, data, buff);
	else
		ft_buffer(c, buff);
	return (0);
}
