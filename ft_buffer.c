/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:00:02 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 08:32:19 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FT_PRINTF.H"

int		ft_buffer(char c)
{
	t_buff	*buff;

	if (buff.buffer == NULL)
	{
		ft_bzero(buff, sizeof(t_buff));
		buff.len = 0;
	}
	if (c == '\n')
	{
		buff.buffer[buff.len] = c;
		ft_putstr(buff.buffer);
		ft_bzero(buff, sizeof(t_buff));
		buff.len = 0;
	}
	else if (c == '\0')
	{
		ft_putstr(buff.buffer);
		return (0);
	}
	else
		buff.buffer[buff.len++] = c;
	if (len == 4096)
	{
		ft_putstr(buff.buffer);
		ft_bzero(buff, sizeof(t_buff);
	}
	return (1);
}

int		ft_buffer_str(char *str)
{
}
