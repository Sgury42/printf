/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/06/01 17:49:28 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hashtag_flag(t_data_tab *data, t_buff *buff)
{
	if ((data->conv == 'x' || data->conv == 'X') && data->flags[zero] == 0)
	{
		ft_buffer('0', buff);
		ft_buffer(data->conv, buff);
	}
	else if (data->conv == 'o')
		ft_buffer('0', buff);
	else if (data->conv == 'p')
		ft_str_to_buff("0x", buff);
}

static void	justify_right(char *str, t_data_tab *data, t_buff *buff)
{
	int	spaces;
	char	c;
	int	neg;

	neg = 0;
	spaces = data->flags[width] - ft_strlen(str);
	if (data->flags[sign] && str[0] != '-')
		spaces -= 1;
	c = ' ';
	if (data->flags[zero] && data->flags[precision] != 'z')
		c = '0';
	if (c == '0')
	{
		if (str[0] == '-')
		{
			ft_buffer('-', buff);
			neg = 1;
		}
		else if (data->flags[sign])
			ft_buffer('+', buff);
	}
	while (spaces > 0)
	{
		ft_buffer(c, buff);
		spaces--;
	}
	if (data->flags[sign] && c != '0' && str[0] != '-')
		ft_buffer('+', buff);
	if (data->flags[hashtag] || data->conv == 'p')
		hashtag_flag(data, buff);
	ft_str_to_buff(str + neg, buff);
}

static void	justify_left(char *str, t_data_tab *data, t_buff *buff)
{
	int	spaces;

	spaces = data->flags[width] - ft_strlen(str) - data->flags[sign];
	if (data->flags[hashtag])
		hashtag_flag(data, buff);
	ft_str_to_buff(str, buff);
	while (spaces > 0)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
}

void		ft_width(char *str, t_data_tab *data, t_buff *buff)
{
	if (data->flags[just_left])
	{
		if (data->conv == 'p')
			ft_str_to_buff("0x", buff);
		if (data->flags[sign] && str[0] != '-')
			ft_buffer('+', buff);
		justify_left(str, data, buff);
	}
	else
	{
		if (data->conv == 'o' && data->flags[hashtag] && data->flags[zero] == 0)
			data->flags[width] -= 1;
		justify_right(str, data, buff);
	}
}
