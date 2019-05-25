/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:50:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/25 15:17:40 by sgury            ###   ########.fr       */
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
    unsigned long long   nbr;
	char				*str;

	nbr = ft_get_unbr(ap, data);
	if ((str = ft_strdup(ft_itoa_base(nbr, 16))) == NULL)
		return (-1);
	if (str[0] == '-')
		neg = 1;
	if (data->flags[L] || data->flags[sign])
		ft_usage('x');
	if (data->flags[width] <= (int)ft_strlen(str))
		data->flags[width] = 0;
	ft_flags_display(0, data, buff);
	if (data->flags[width])
		ft_width(str, data, buff);
	else
		ft_str_to_buff(str, buff);
	ft_strdel(&str);
    return (1);
}
