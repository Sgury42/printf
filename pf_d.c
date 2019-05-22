/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/22 15:56:09 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_d(va_list ap, t_data_tab *data)
{
	char	*str;
	int		i;

	if (data->flags[L] || data->flags[#])
		ft_usage();
	if ((str = ft_strdup(ft_get_str(ap, data))) == NULL)
		return (-1);
	return (0);
}
