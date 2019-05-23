/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:07:27 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/23 17:14:45 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_s(va_list ap, t_data_tab *data, t_buff *buff)
{
	char	*str;
	int		i;

	i = 0;
    str = va_arg(ap, char *);
	if ((str = ft_strdup(str)) == NULL)
		return (-1);
	while (++i < 10)
		if (data->flags[i] || data->flags[precision])
			ft_usage('s');
	if (data->flags[width])
		ft_width(str, data, buff);
	else
		ft_str_to_buff(str, buff);
	ft_strdel(&str);
	return (0);
}
