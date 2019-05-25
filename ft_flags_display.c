/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:34:09 by sgury             #+#    #+#             */
/*   Updated: 2019/05/25 11:47:15 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_display(int neg, t_data_tab *data, t_buff *buff)
{
	if (data->flags[space] && neg == 0)
		ft_buffer(' ', buff);
	if (data->flags[zero] && (data->flags[sign] || neg))
	{
		if (neg)
			ft_buffer('-', buff);
		else
			ft_buffer('+', buff);
		data->flags[width] -= 1;
	}
}
