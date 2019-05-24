/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/24 17:50:36 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TEST

/*static char     *pf_toupper(char *str)*/
/*{*/
    /*while (*str)*/
    /*{*/
        /*if (*str >= 'a' && *str <= 'z')*/
            /**str -= 32;*/
        /*++str;*/
    /*}*/
    /*return (str);*/
/*}*/

int		pf_x(va_list ap, t_data_tab *data, t_buff *buff)
{
    long long   nbr;

    (void)data;
    nbr = va_arg(ap, long long);
    ft_str_to_buff(ft_itoa_base(nbr, 16), buff);
    return (1);
}
