/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/24 14:38:17 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_data(char *str, t_data_tab *data)
{
	if (data->flags[L] || data->flags[hashtag])
		ft_usage('d');
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
}

static void	display_sign(t_data_tab *data, int neg, t_buff *buff)
{
	if (neg)
		ft_buffer('-', buff);
	else
		ft_buffer('+', buff);
	data->flags[width] -= 1;
}

int			pf_d(va_list ap, t_data_tab *data, t_buff *buff)
{
	char	*str;
	int		neg;

	neg = 0;
	if ((str = ft_strdup(ft_get_str(ap, data))) == NULL)
		return (-1);
	check_data(str, data);
	if (str[0] == '-')
		neg = 1;
	if (data->flags[space] && neg == 0)
		ft_buffer(' ', buff);
	if (data->flags[zero] && (data->flags[sign] || neg))
		display_sign(data, neg, buff);
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
