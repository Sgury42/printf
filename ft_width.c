/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:51:48 by sgury             #+#    #+#             */
/*   Updated: 2019/05/22 10:50:06 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void just_right(char *str, int spaces, int zero, t_buff *buff)
{
	char	c;

	c = ' ';
	if (zero)
		c = '0';
	while (spaces > 0)
	{
		ft_buffer(c, buff);
		spaces--;
	}
	ft_str_to_buff(str, buff);
}

static void	just_left(char *str, int spaces, t_buff *buff)
{
	ft_str_to_buff(str, buff);
	while (spaces > 0)
	{
		ft_buffer(' ', buff);
			spaces--;
	}
}

void	ft_width(char *str, t_data_tab *data, t_buff *buff)
{
	int		spaces;

	spaces = data->flags[10] - ft_strlen(str);
	if (data->flags[0])
	{
		if (data->flags[3])
			ft_usage();
		just_left(str, spaces, buff);
	}
	else
		just_right(str, spaces, data->flags[3], buff);
}
