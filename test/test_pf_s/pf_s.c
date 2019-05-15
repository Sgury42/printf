/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:07:27 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/15 11:12:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     pf_s(va_list ap, t_data_tab *datas)
{
    char *ret;
    
    ft_putstr(va_arg(ap, char *));
    va_end(ap);
    return (1);
}

/*int     job_control_test(t_data_tab *datas, ...)*/
/*{*/
    /*va_list ap;*/
    /*va_start(ap, datas);*/
    /*pf_s(ap, datas);*/
    /*va_end(ap);*/
    /*return (1);*/
/*}*/
