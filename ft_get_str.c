/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:02:22 by sgury             #+#    #+#             */
/*   Updated: 2019/05/22 14:28:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_get_str(va_list ap, t_data_tab *data)
{
	char	*str;

	if (data->flags[h])
		return (ft_itoa(va_arg(ap, short)));
	else if (data->flags[hh])
		return (va_arg(ap, char *));
	else if (data->flags[l])
		return (ft_itoa(va_arg(ap, long)));
	else if (data->flags[ll])
		return (ft_itoa(va_arg(ap, long long)));
	else
		return (va_arg(ap, int));
}
