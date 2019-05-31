/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:38:41 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/31 10:11:55 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_p(va_list ap, t_data_tab *data, t_buff *buff)
{
	long long	nbr;
        char            *str;

	(void)data;
	nbr = va_arg(ap, long long);
	ft_str_to_buff("0x", buff);
	if ((str = ft_itoa_base(nbr, 16), buff) == NULL)
            return (-1);
	ft_str_to_buff(str, buff);
	ft_strdel(&str)
	return (0);
}
