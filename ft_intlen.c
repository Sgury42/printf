/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:22:15 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/30 12:14:01 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_intlen(long long nb)
{
    int count;

    count = 1;
    while (nb)
    {
        ++count;
        nb /= 10;
    }
    return (count);
}
