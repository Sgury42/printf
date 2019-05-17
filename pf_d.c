/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 11:28:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/17 14:08:20 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pf_d(va_list ap, t_data_tab *datas)
{
    /*unsigned char   *str;*/
    /*int             i;*/

    /*i = 0;*/
    /*if (!ft_strcmp(datas->flags, "h") || !ft_strcmp(datas->flags, "l")*/
            /*|| !ft_strcmp(datas->flags, "ll"))*/
        /*if (ft_str)*/
        /*ft_putnbr(va_arg(ap, long long));*/
    /*else if (!ft_strcmp(datas->flags, "hh"))*/
    /*{*/
    /*}*/
    return (ft_itoa(va_arg(ap, int)));
}
