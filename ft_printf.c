/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 11:50:38 by sgury            ###   ########.fr       */
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
	ft_bzero(data, sizeof(t_data_tab));
	ft_bzero(&buff, sizeof(t_buff));
	buff.len = 0;
	index = 0;
	while((index = ft_parse(format, data, index, &buff)) > 0)
	{
		str = ft_dispatcher(ap, data);
		ft_str_to_buff(str, &buff);
		ft_bzero(data, sizeof(t_data_tab));
		printf("test\n");
	}
	if (index < 0)
		return (ft_usage());                            //need to return usage error
	ft_putstr(buff.buffer);
	va_end(ap);
	free(data);
}
