/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/30 13:55:53 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_x(va_list ap, t_data_tab *data, t_buff *buff)
{
	unsigned long long	nbr;
	char				*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa_base(nbr, 16)) == NULL)
		return (-1);
	if (data->flags[sign])
		data->flags[sign] = 0;
	if (data->flags[hashtag] && data->flags[zero])
	{
		ft_str_to_buff("0x", buff);
		data->flags[width] -= 2;
	}
	if (data->flags[width] && (data->flags[width] > (int)ft_strlen(str)))
		ft_width(str, data, buff);
	else
		ft_str_to_buff(str, buff);
	ft_strdel(&str);
	return (0);
}
