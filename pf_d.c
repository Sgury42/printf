/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 11:41:23 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_d(va_list ap, t_data_tab *data, t_buff *buff)
{
	char	*str;
	int		neg;

	neg = 0;
	if ((str = ft_strdup(ft_get_str(ap, data))) == NULL)
		return (-1);
	if (data->flags[L] || data->flags[hashtag])
		ft_usage('d');
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
