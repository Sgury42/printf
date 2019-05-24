/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:39:04 by sgury             #+#    #+#             */
/*   Updated: 2019/05/23 17:07:58 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(t_data_tab *data)
{
	int		flag_count;

	flag_count = 0;
	if (data->flags[L])
		flag_count++;
	if (data->flags[h])
		flag_count++;
	if (data->flags[l])
		flag_count++;
	if (data->flags[hh])
		flag_count++;
	if (data->flags[ll])
		flag_count++;
	if (flag_count > 1 || (data->flags[zero] && data->flags[just_left])
			|| (data->flags[space] && data->flags[sign]))
		ft_usage(data->conv);
}
