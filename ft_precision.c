/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:34:36 by sgury             #+#    #+#             */
/*   Updated: 2019/06/05 23:34:47 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	left_justify(char *str, int neg, t_data_tab *data, t_buff *buff)
{
	int	prec;
	int	spaces;

	spaces = 0;
	prec = data->flags[precision] - (int)ft_strlen(str);
	if (data->flags[width] > data->flags[precision])
		spaces = data->flags[width] - data->flags[precision] - neg;
	if (data->flags[width] == 0 && data->flags[space])
		spaces = 1;
	while (prec > 0)
	{
		ft_buffer('0', buff);
		prec--;
	}
	ft_str_to_buff(str, buff);
	while (spaces > 0)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
}

static void	right_justify(char *str, int neg, t_data_tab *data, t_buff *buff)
{
	int	prec;
	int	spaces;

	spaces = 0;
	prec = data->flags[precision] - (int)ft_strlen(str) + neg;
	if (data->flags[width] > data->flags[precision])
		spaces = data->flags[width] - data->flags[precision] - neg;
	if (data->flags[width] == 0 && data->flags[space])
		spaces = 1;
	if (neg == 0 && data->flags[sign])
		spaces -= 1;
	while (spaces > 0)
	{
		ft_buffer(' ', buff);
		spaces--;
	}
	if (neg)
		ft_buffer('-', buff);
	else if (data->flags[sign])
		ft_buffer('+', buff);
	while (prec > 0)
	{
		ft_buffer('0', buff);
		prec--;
	}
	ft_str_to_buff(str + neg, buff);
}

void	ft_precision(char *str, t_data_tab *data, t_buff *buff)
{
	int	neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1;
	if (data->flags[space])
		if (neg || data->flags[sign])
			data->flags[space] = 0;
	if (data->flags[just_left])
	{
		if (neg)
			ft_buffer('-', buff);
		else if (data->flags[sign])
		{
			ft_buffer('+', buff);
			data->flags[width] -= 1;
		}
		left_justify(str + neg, neg, data, buff);
	}
	else 
		right_justify(str, neg, data, buff);
}
