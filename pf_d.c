/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/15 12:06:29 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_d(va_list ap, t_data_tab *datas)
{
    unsigned char   *str;
    int             i;

    i = 0;
    if (!ft_strcmp(datas->flags, "h") || !ft_strcmp(datas->flags, "l") || !ft_strcmp(datas->flags, "ll"))
        ft_putnbr(va_arg(ap, long long));
    else if (!ft_strcmp(datas->flags, "hh"))
    {
    }
}
