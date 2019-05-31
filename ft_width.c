/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/31 09:57:54 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_right(char *str, t_data_tab *data, t_buff *buff)
{
	int		spaces;
	char	c;

	spaces = data->flags[width] - ft_strlen(str) - data->flags[sign];
	if (data->flags[sign])
		spaces += data->flags[zero];
	c = ' ';
	if (data->flags[zero])
		c = '0';
	while (spaces > 0)
	{
		ft_buffer(c, buff);
		spaces--;
	}
	if (data->flags[sign] && c != '0')
		ft_buffer('+', buff);
	if (data->flags[hashtag] && c != '0'
			&& (data->conv == 'x' || data->conv == 'X'))
		ft_str_to_buff("0x", buff);
	ft_str_to_buff(str, buff);
}

static void	justify_left(char *str, t_data_tab *data, t_buff *buff)
{
	int	flag_sign;
	int	spaces;

	flag_sign = data->flags[sign];
	spaces = data->flags[width] - ft_strlen(str) - flag_sign;
	if (flag_sign)
		ft_buffer('+', buff);
	if (data->flags[hashtag] && (data->conv == 'x' || data->conv == 'X'))
		ft_str_to_buff("0x", buff);
	ft_str_to_buff(str, buff);
	while (spaces > 0)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
}

void	ft_width(char *str, t_data_tab *data, t_buff *buff)
{
	if (data->flags[just_left])
	{
		if (data->flags[zero])
			ft_usage(data->conv);
		justify_left(str, data, buff);
	}
	else
		justify_right(str, data, buff);
}
