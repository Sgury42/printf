/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:33 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 08:32:16 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_nbr(char *str, t_data_tab *data, int index)
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
		data->precision = nbr;
	else
		data->width = nbr;
	return (index);
}

int		ft_get_flag(char *str, t_data_tab *data, int index)
{
	int	*flags_address[FLAGS_NB] = {&data->just_left, &data->sign,
		&data->space, &data->zero, &data->hashtag, &data->h, &data->l, &data->L};
	char	flags_char[FLAGS_NB] = {'-', '+', ' ',
		'0', '#', 'h', 'l', 'L'};
	int			i;

	i = 0;
	while (str[index] != flags_char[i] && i < FLAGS_NB)
		i++;
	if ((i == 5 || i == 6) && str[index] == str[index + 1])
	{
		if (str[index] == 'h')
			data->hh = 1;
		if (str[index] == 'l')
			data->ll = 1;
		return (index + 2);
	}
	if (str[index] != flags_char[i])
		return (ft_get_nbr(str, data, index));
	*flags_address[i] = 1;
	return (++index);
}

int		ft_get_data(char *str, t_data_tab *data, int index)
{
	static char	conv[NB_CONV] = "sdiouxXfcp";
	int			i;

	i = 0;
	if (str[++index] == '%')
	{
		ft_putchar('%');
		return (++index);
	}
	while (str[index] != conv[i])
	{
		while (str[index] != conv[i] && i < NB_CONV)
			i++;
		if (i == NB_CONV && str[index] != conv[i])
		{
			index = ft_get_flag(str, data, index);
			i = 0;
		}
	}
	data->conv = str[index++];
	return (index);
}

int		ft_parse(char *str, t_data_tab *data, int index)
{
	while (str[index] != '\0' && str[index] != '%')
		ft_buffer(str[index++]);
	if (str[index] == '%')
	{
		if ((index = ft_get_data(str, data, index)))
			return (index);
	}
	return (0);
}
