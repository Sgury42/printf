/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/05/15 11:23:27 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_printf(const char *format, ...)
{
	t_data_tab	*data;
	int			index;
	va_list		ap;

	va_start(ap, format);
	if ((data = (t_data_tab *)malloc(sizeof(t_data_tab))) == NULL)
		return ;
	index = 0;
        pf_s(ap, data);
	/*while((index = ft_parse(format, data, index)) > 0)*/
	/*{*/
		/*if (ft_dispatcher(ap, data) < 0)*/
			/*return ;*/
		/*ft_bzero(data->flags, FLAG_MAX);*/
		/*data->conv = '\0';*/
	/*}*/
	va_end(ap);
	/*ft_free_data(data);*/
}

#include <stdio.h>

int     main()
{
    ft_printf("test", "Hello World\n");
    printf("%s", "Hello World\n");
    return (0);
}