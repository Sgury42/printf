/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_upperx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:26:06 by sgury             #+#    #+#             */
/*   Updated: 2019/06/07 13:34:39 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_upperx(va_list ap, t_data_tab *data, t_buff *buff)
{
	unsigned long long	nbr;
	char				*str;
	int					i;

	i = -1;
	nbr = ft_get_unbr(ap, data);
	if ((str = ft_itoa_base(nbr, 16)) == NULL)
		return (-1);
	while (str[++i])
		str[i] = ft_toupper(str[i]);
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
			ft_str_to_buff("0X", buff);
		ft_width(str, data, buff);
	}
	else
	{
		if (data->flags[hashtag])
			ft_str_to_buff("0X", buff);
		ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
