/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:47:22 by sgury             #+#    #+#             */
/*   Updated: 2019/05/25 11:35:30 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_nbr(va_list ap, t_data_tab *data)
{
	long long	nbr;

	nbr = va_arg(ap, long long);
	if (data->flags[hh])
	{
		if (nbr < -128 || nbr > 127)
			ft_size_error(data);
	}
	else if (data->flags[h])
	{
		if (nbr < -32768 || nbr > 32767)
			ft_size_error(data);
	}
	else if (data->flags[l])
	{
		if (nbr < -2147483648 || nbr > 2147483647)
			ft_size_error(data);
	}
	else if (data->flags[ll] == 0)
	{
		if (nbr < -2147483648 || nbr > 2147483647)
			ft_size_error(data);
	}
	return (nbr);
}
