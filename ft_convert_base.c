/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:32:14 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/22 16:26:28 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      val_check(char c)
{
    if (c >= '0' && c <= '9')
        return ((int)c - '0');
    else
        return ((int)c - 'A' + 10);
}

int     convert_base_to_dec(char *str, int base)
{
    int len;
    int result;
    int power;
    int i;

    len = ft_strlen(str);
    result = 0;
    power = 1;
    i = len;
    while (--i >= 0)
    {
        if (val_check(str[i]) >= base)
            return (-1);
        result += val_check(str[i]) * power;
        power *= base;
    }
    return (result);
}
