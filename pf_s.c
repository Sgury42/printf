/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:07:27 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/21 16:17:05 by sgury            ###   ########.fr       */
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
		if (data->flags[i] || data->flags[11])
			ft_usage();
	if (data->flags[10])
		ft_width(str, data, buff);
	else
		ft_str_to_buff(str, buff);
	free(str);
	return (0);
}
