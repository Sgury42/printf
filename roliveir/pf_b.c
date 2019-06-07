/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 21:24:12 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/07 02:59:34 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		pf_b(va_list ap, t_data_tab *data, t_buff *buff)
{
	unsigned long long	nbr;
	char			*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa_base(nbr, 2)) == NULL)
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
	return (0);
}
