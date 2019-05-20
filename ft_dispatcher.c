/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/20 16:43:40 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dispatcher(va_list ap, t_data_tab *data, t_buff *buff)
{
    int     i;

    i = 0;
    static char *fct_name[NB_FUNC] = {"c"};
    while (i < NB_FUNC)
    {
        if (!ft_strcmp(&data->conv, fct_name[i]))
            break ;
        i++;
    }
    static int (*fct_list[NB_FUNC])(va_list, t_data_tab *, t_buff *) = {pf_c};
    if (i >= 0 && i < NB_FUNC)
        return ((fct_list[i]))(ap, data, buff);
    return (-1);
}
