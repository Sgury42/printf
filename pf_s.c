/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:07:27 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/08 21:24:54 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_prec(char *str, int len, t_buff *buff)
{
	int	i;

	i = 0;
	if (len == 'z')
		len = 0;
	while (str[i] && i < len)
		ft_buffer(str[i++], buff);
}

static void	str_width(char *str, t_data_tab *data, t_buff *buff)
{
	int	spaces;

	if (data->flags[precision] && data->flags[precision] < (int)ft_strlen(str))
		spaces = data->flags[width] - data->flags[precision];
	else
		spaces = data->flags[width] - ft_strlen(str);
	if (data->flags[just_left])
	{
		if (data->flags[precision])
			str_prec(str, data->flags[precision], buff);
		else
			ft_str_to_buff(str, buff);
		while (spaces-- > 0)
			ft_buffer(' ', buff);
	}
	else
	{
		while (spaces-- > 0)
			ft_buffer(' ', buff);
		if (data->flags[precision])
			str_prec(str, data->flags[precision], buff);
		else
			ft_str_to_buff(str, buff);
	}
}

int			pf_s(va_list ap, t_data_tab *data, t_buff *buff)
{
	char	*str;

	if ((str = va_arg(ap, char *)) == NULL)
		str = "(null)";
	if ((str = ft_strdup(str)) == NULL)
		return (-1);
	if (data->flags[width])
		str_width(str, data, buff);
	else
	{
		if (data->flags[precision])
			str_prec(str, data->flags[precision], buff);
		else
			ft_str_to_buff(str, buff);
	}
	ft_strdel(&str);
	return (0);
}
