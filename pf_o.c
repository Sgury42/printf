/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:49:55 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 15:57:05 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		pf_o(va_list ap, t_data_tab *data, t_buff *buff)
{
    unsigned long long   nbr;
	char				*str;

    nbr = ft_get_unbr(ap, data);
	if ((str = ft_strdup(ft_itoa_base(nbr, 8))) == NULL)
		return (-1);
	if (data->flags[sign])
		data->flags[sign] = 0;
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	if (data->flags[width])
		ft_width(str, data, buff);
	else
		ft_str_to_buff(str, buff);
	ft_strdel(&str);
    return (1);
}
