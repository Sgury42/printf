/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:00:25 by sgury             #+#    #+#             */
/*   Updated: 2019/06/07 12:02:14 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unflag(t_data_tab *data)
{
	if (data->flags[sign])
		data->flags[sign] = 0;
//	if (data->flags[precision])
//		data->flags[precision] = 0;
}
