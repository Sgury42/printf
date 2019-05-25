/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 18:37:39 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dispatcher(va_list ap, t_data_tab *data, t_buff *buff)
{
    int     i;

    i = 0;
    static char *fct_name[NB_FUNC] = {"c", "s", "d", "x", "o", "p", "u"};
    while (i < NB_FUNC)
    {
        if (!ft_strcmp(&data->conv, fct_name[i]))
            break ;
        i++;
    }
    static int (*fct_list[NB_FUNC])(va_list, t_data_tab *, t_buff *) = {pf_c, pf_s, pf_d, pf_x, pf_o, pf_p, pf_u};
    if (i >= 0 && i < NB_FUNC)
	{
        return ((fct_list[i]))(ap, data, buff);
	}
    return (-1);
}
