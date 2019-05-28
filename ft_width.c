/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/27 12:05:18 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_right(char *str, t_data_tab *data, t_buff *buff)
{
	int		flag_sign;
	int		spaces;
	int		flag_zero;
	char	c;

	flag_sign = data->flags[sign];
	flag_zero = data->flags[zero];
	spaces = data->flags[width] - ft_strlen(str) - flag_sign;
	if (flag_sign)
		spaces += flag_zero;
	c = ' ';
	if (flag_zero)
		c = '0';
	while (spaces > 0)
	{
		ft_buffer(c, buff);
		spaces--;
	}
	if (flag_sign && c != '0')
		ft_buffer('+', buff);
	if (data->flags[hashtag] && (data->conv == 'x' || data->conv == 'X'))
	{
		ft_str_to_buff("0x", buff);
		spaces -= 2;
	}
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
	{
		ft_str_to_buff("0x", buff);
		spaces -= 2;
	}
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
		justify_left(str, data, buff);
	else
		justify_right(str, data, buff);
}
