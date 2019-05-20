/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:32:14 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/20 11:58:09 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     ft_is_spaces(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int     ft_convert_base(char *str)
{
    int     result;
    int     neg;

    result = 0;
    neg = 1;
    while (ft_is_spaces(*str))
        ++str;
    if (*str == '-')
        neg = -1;
    if (*str == '+' || *str == '-')
        ++str;
    while (ft_isdigit(*str))
    {
        result *= 10;
        result += *str - 48;
        ++str;
    }
    return (result * neg);
}

int     main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("[ERROR]: USAGE -> [./a.out] [NUMBER]");
        return (0);
    }
    printf("%d\n", ft_convert_base(av[1]));
    return (0);
}
