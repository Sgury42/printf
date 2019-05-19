/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:33 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 16:06:28 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_nbr(char *str, t_data_tab *data, int index)
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
		data->flags[11] = nbr;
	else
		data->flags[10] = nbr;
	return (index);
}

static int		ft_get_flag(char *str, t_data_tab *data, int index)
{
	static char	flags_char[FLAGS_NB] = {'-', '+', ' ',
		'0', '#', 'L', 'h', 'l'};
	int			i;

	i = 0;
	while (str[index] != flags_char[i] && i < FLAGS_NB)
		i++;
	if ((i == 6 || i == 7) && str[index] == str[index + 1])
	{
		data->flags[i + 2] = 1;
		return (index + 2);
	}
	if (str[index] != flags_char[i]
			&& (ft_isdigit(str[index]) || str[index] == '.'))
		return (ft_get_nbr(str, data, index));
	if (str[index] == flags_char[i])
		data->flags[i] = 1;
	else
		return (-1);
	return (++index);
}

static int		ft_get_data(char *str, t_data_tab *data, int index)
{
	static char	conv[NB_CONV] = "sdiouxXfcp";
	int			i;

	i = 0;
	if (str[++index] == '%')
	{
		ft_putchar('%');
		return (++index);
	}
	while (str[index] != conv[i] && i < NB_CONV)
		i++;
	if (i == NB_CONV && str[index] != conv[i])
	{
		if ((index = ft_get_flag(str, data, index)) < 0)
			return (-1);
		i = 0;
	}
	data->conv = str[index++];
	return (index);
}

int				ft_parse(char *str, t_data_tab *data, int index, t_buff *buff)
{
	while (str[index] != '\0' && str[index] != '%')
		ft_buffer(str[index++], buff);
	if (str[index] == '%')
	{
		if ((index = ft_get_data(str, data, index)) < 0)
			return (-1);
		return (index);
	}
	return (0);
}
