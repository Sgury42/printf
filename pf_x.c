/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/07 13:34:41 by sgury            ###   ########.fr       */
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
	ft_unflag(data);
	if (nbr == 0 && data->flags[precision] == 'z')
	{
		if (data->flags[width] == 0)
			str[0] = '\0';
		else
			str[0] = ' ';
		data->flags[hashtag] = 0;
	}
	if (data->flags[hashtag])
		data->flags[width] -= 2;
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	if (data->flags[precision] != 'z'
			&& data->flags[precision] >= (int)ft_strlen(str))
		ft_precision(str, data, buff);
	else if (data->flags[width])
	{
		if (data->flags[hashtag] && data->flags[zero])
			ft_str_to_buff("0x", buff);
		ft_width(str, data, buff);
	}
	else
	{
		if (data->flags[hashtag])
			ft_str_to_buff("0x", buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
