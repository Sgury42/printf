/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 08:35:31 by sgury             #+#    #+#             */
/*   Updated: 2019/05/20 10:45:24 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_c(va_list ap, t_data_tab *data)
{
//	char	c;
	int		i;
	char	*str;
	int		just_left;

	i = 0;
	just_left = 0;
	while (++i < 10)
		if (data->flags[i] || data->flags[11])
			ft_usage();
	str = va_arg(ap, char *);
//	str = &c;
	if (data->flags[10])
	{
		if (data->flags[0])
			just_left = 1;
		str = ft_width(str, data->flags[10], just_left);
	}
	return (str);
}
