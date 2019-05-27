/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:33 by sgury             #+#    #+#             */
/*   Updated: 2019/05/27 10:56:13 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_int(const char *str, t_data_tab *data, int index)
{
	int	nbr;
	int	precision;

	nbr = 0;
	precision = 0;
	if (str[index] == '.')
	{
		precision = 1;
		index++;
	}
	if (ft_isdigit(str[index]))
	{
		nbr = nbr * 10 + ft_atoi(&str[index]);
		while (ft_isdigit(str[index]))
			index++;
	}
	if (precision)
		data->flags[precision] = nbr;
	else
		data->flags[width] = nbr;
	return (index);
}

static int		ft_get_flag(const char *str, t_data_tab *data, int index)
{
	static char	flags_char[FLAGS_NB] = {'-', '+', ' ',
		'0', '#', 'L', 'h', 'l'};
	int			i;

	i = 0;
	while (i < FLAGS_NB && str[index] != flags_char[i])
		i++;
	if ((i == 6 || i == 7) && str[index] == str[index + 1])
	{
		data->flags[i + 2] = 1;
		return (index + 2);
	}
	if (i == FLAGS_NB && (ft_isdigit(str[index]) || str[index] == '.'))
		return (ft_get_int(str, data, index));
	if (i < FLAGS_NB && str[index] == flags_char[i])
		data->flags[i] = 1;
	else
		return (-1);
	return (++index);
}

static int		ft_get_data(const char *str, t_data_tab *data, int index, t_buff *buff)
{
	static char	conv[NB_CONV] = "sdiouxXfcp";
	int			i;

	i = 0;
	if (str[++index] == '%')
	{
		ft_buffer('%', buff);
		data->conv = '%';
		return (++index);
	}
	while (i < NB_CONV && str[index] != conv[i])
	{
		while (i < NB_CONV && str[index] != conv[i])
			i++;
		if (i == NB_CONV)
		{
			if ((index = ft_get_flag(str, data, index)) < 0)
				return (-1);
			i = 0;
		}
	}
	data->conv = str[index];
	return (++index);
}

int				ft_parse(const char *str, t_data_tab *data, int index, t_buff *buff)
{
	while (str[index] != '\0' && str[index] != '%')
		ft_buffer(str[index++], buff);
	if (str[index] == '%')
	{
		if ((index = ft_get_data(str, data, index, buff)) < 0)
			return (-1);
		return (index);
	}
	return (0);
}
