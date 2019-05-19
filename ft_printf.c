/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/05/19 14:51:10 by sgury            ###   ########.fr       */
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
	char		*str;

	va_start(ap, format);
	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		return ;
	ft_bzero(&buff, sizeof(t_buff));
	buff.len = 0;
	index = 0;
	while((index = ft_parse(format, data, index, &buff)) > 0)
	{
		if ((str = ft_dispatcher(ap, data)) != NULL)
			return ;
		ft_str_to_buffer(str);
		ft_bzero(data, sizeof(t_data_tab));
	}
	va_end(ap);
	free(data);
}
