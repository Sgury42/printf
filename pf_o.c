/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:49:55 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 11:47:19 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		pf_o(va_list ap, t_data_tab *data, t_buff *buff)
{
    long long   nbr;
	char		*str;
	int			neg;

	neg = 0;
    nbr = ft_get_nbr(ap, data);
	if ((str = ft_strdup(ft_itoa_base(nbr, 8))) == NULL)
		return (-1);
	if (str[0] == '-')
		neg = 1;
	if (data->flags[L] || data->flags[hashtag] || data->flags[sign])
		ft_usage('o');
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
    return (1);
}
