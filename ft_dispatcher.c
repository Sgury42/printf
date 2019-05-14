/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/14 18:55:01 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_dispacher(va_list ap, t_data_tab *data)
{
    int     i;

    i = 0;
    static char *fct_name[NB_FUNC] = {"c", "s", "d"};
    while (i < NB_FUNC)
    {
        if (!ft_strcmp(data->conv, fct_name[i]))
            break ;
        i++;
    }
    static int  (*fct_list[NB_FUNC])(va_list, t_data_tab *) = {pf_c, pf_s, pf_d};
    if (i >= 0 && i < NB_FUNC)
        return (*(fct_list[i]))(ap, data);
    return (-1);
}
