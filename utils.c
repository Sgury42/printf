/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:15:28 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/15 15:29:08 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_zero(char *str, int size)
{
    int len;

    len = (size - ft_strlen(str));
    if (len < 0)
        return (0);
    while (len)
    {
        ft_putchar('0');
        --len;
    }
    return (1);
}

int ft_print_spaces(char *str,int size)
{
    int len;

    len = (size - ft_strlen(str));
    if (len < 0)
        return (0);
    while (len)
    {
        ft_putchar(' ');
        --len;
    }
    return (1);
}
