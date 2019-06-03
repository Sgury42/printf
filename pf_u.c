/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:22:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/03 04:29:05 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_u(va_list ap, t_data_tab *data, t_buff *buff)
{
	unsigned long long	nbr;
	char				*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa((long long)nbr)) == NULL)
		return (-1);
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	ft_flags_display(0, data, buff);
	if (data->flags[width])
		ft_width(str, data, buff);
	else
	{
		if (data->flags[sign])
			ft_buffer('+', buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
