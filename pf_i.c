/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:46:13 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/30 13:44:47 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_i(va_list ap, t_data_tab *data, t_buff *buff)
{
	long long int	nbr;
	char			*str;
	int				neg;

	neg = 0;
	nbr = ft_get_nbr(ap, data);
	if ((str = ft_itoa(nbr)) == NULL)
		return (-1);
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	ft_flags_display(neg, data, buff);
	if (data->flags[width])
		ft_width(str + neg, data, buff);
	else
	{
		if (data->flags[sign] && neg == 0)
			ft_buffer('+', buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
