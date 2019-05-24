/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:49:55 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/24 17:50:27 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		pf_o(va_list ap, t_data_tab *data, t_buff *buff)
{
    long long   nbr;

    (void)data;
    nbr = va_arg(ap, long long);
    ft_str_to_buff(ft_itoa_base(nbr, 8), buff);
    return (1);
}
