/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 03:03:31 by sgury             #+#    #+#             */
/*   Updated: 2019/06/08 21:27:05 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_percentage(va_list ap, t_data_tab *data, t_buff *buff)
{
	int	spaces;

	(void)ap;
	spaces = data->flags[width];
	if (data->flags[just_left])
	{
		ft_buffer('%', buff);
		while (--spaces > 0)
			ft_buffer(' ', buff);
	}
	else
	{
		while (--spaces > 0)
			ft_buffer(' ', buff);
		ft_buffer('%', buff);
	}
	return (0);
}
