/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:28:33 by sgury             #+#    #+#             */
/*   Updated: 2019/05/17 11:18:33 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_nbr(char *str, int index)
{
	int	nbr;
	int	precision;

	nbr = 0;
	precision = 0;
	if (str[index++] == '.')
		precision = 1;
	while (ft_isdigit(str[index]))
		nbr = nbr * 10 + str[index++];
	if (precision)
		data.precision = nbr;
	else
		data.width = nbr;
	return (index);
}

int		ft_get_flag(char *str, t_data_tab data, int index)
{
	static int	*flags_address[FLAGS_NB] = {&data.just_left, &data.sign,
		&data.space, &data.zero, &data.hashtag, &data.h, &data.l, &data.L};
	static char	*flags_char[FLAGS_NB] = {'-', '+', ' ',
		'0', '#', 'h', 'l', 'L'};
	int			i;
	int			precision;

	while (str[index] != flags_char[i] && i < FLAGS_NB)
		i++;
	if ((i == 5 || i == 6) && str[index] == str[index + 1])
	{
		if (str[index] == 'h')
			data.hh = 1;
		if (str[index] == 'l')
			data.ll = 1;
		return (index + 2);
	}
	if (str[index] != flags_char[i])
		return (ft_get_nbr(str, index));
	*flags_address[i] = 1;
	return (++index);
}

int		ft_get_data(char *str, t_data_tab data, int index)
{
	char	conv[NB_CONV] = "sdiouxXfcp";
	int		i;

	i = 0;
	if (str[++index] == '%')
	{
		ft_putchar('%');
		return (++index);
	}
	while (str[index] != conv[i])
	{
		while (i < NB_CONV && str[index] != conv[i])
			i++;
		if (i == NB_CONV && str[index] != conv[i])
			index = ft_get_flag(str, data, index);
		i = 0;
	}
	data.conv = str[index++];
}

int		ft_parse(char *str, t_data_tab data, int index)
{
	while (str[index] != '\0' && str[index] != '%')
		ft_putchar(str[index++]);
	if (str[index] == '%')
	{
		if ((index = ft_get_data(str, data, index)))
			return (index);
	}
	return (0);
}
