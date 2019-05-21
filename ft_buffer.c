/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:00:02 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 14:52:42 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_buffer(char c, t_buff *buff)
{
	if (c == '\n')
	{
		buff->buffer[buff->len] = c;
		ft_putstr(buff->buffer);
		ft_bzero(buff->buffer, sizeof(buff->buffer));
		buff->len = 0;
		return (1);
	}
	else
		buff->buffer[buff->len++] = c;
	if (buff->len == BUFF_SIZE)
	{
		ft_putstr(buff->buffer);
		ft_bzero(buff->buffer, sizeof(buff->buffer));
		buff->len = 0;
	}
	return (1);
}
