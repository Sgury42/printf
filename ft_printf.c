/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/03 03:09:23 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	ft_printf(const char *format, ...)
{
	t_data_tab	*data;
	t_buff		buff;
	int			index;
	va_list		ap;

	va_start(ap, format);
	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		exit(-1);
	ft_memset(data, '\0', sizeof(t_data_tab));
	ft_bzero(&buff, sizeof(t_buff));
	buff.len = 0;
	index = 0;
	while ((index = ft_parse(format, data, index, &buff)) > 0)
	{
		if (data->conv)
		{
			if (ft_dispatcher(ap, data, &buff) < 0)
				exit(-1);
		}
		ft_memset(data, '\0', sizeof(t_data_tab));
	}
	if (index < 0)
	{
		printf("test return");
		exit(-1);
	}
	ft_putstr(buff.buffer);
	va_end(ap);
	free(data);
	exit(buff.len);
}
